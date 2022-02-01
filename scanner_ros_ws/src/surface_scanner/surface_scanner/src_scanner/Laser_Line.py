from cv2 import THRESH_OTSU
import numpy as np
import cv2 as cv


def extracting_laser_line(laser_img, threshold: int):
    # create red mask to mark laser pixel
    red_mask = np.zeros((laser_img.shape[0], laser_img.shape[1], laser_img.shape[2]), np.uint8)
    red_mask[:] = (0, 0, 255)
    # smoothen the difference image
    img_blur = cv.GaussianBlur(laser_img, (5, 5), 0)
    # applying threshold
    img_gray = cv.cvtColor(img_blur, cv.COLOR_BGR2GRAY)
    ret, thresh = cv.threshold(img_gray, threshold, 255, cv.THRESH_BINARY)
    # -> other solutions to extract red pixel
    # blue, green, red = cv.split(thresh)
    # red_binary = cv.inRange(red, 20, 255)

    # filter pixel
    filtered_laser_line = cv.bitwise_and(red_mask, red_mask, mask=thresh)

    cv.destroyAllWindows()

    return filtered_laser_line


def get_line_pixels(diff_img_laser):
    img_diff = cv.cvtColor(diff_img_laser, cv.COLOR_BGR2GRAY)

    x = np.array([])
    y = np.array([])

    # describes the deviation from the middle point
    mat = np.matrix([
        [1, -1, 1],
        [0, 0, 1],
        [1, 1, 1]])

    # calculate threshold with otsu
    threshold, binary_img = cv.threshold(img_diff, 0, 255, cv.THRESH_BINARY+THRESH_OTSU)
    print(f"INFO: calculated threshold is: {threshold}")

    row_index = 0

    for row in img_diff:
        max_intensity = np.amax(row)

        # apllying threshold
        if max_intensity <= threshold:
            row_index += 1
            continue

        max_intensity_indices = np.argwhere(row == max_intensity)

        if len(max_intensity_indices) > 1:
            max_intensity_index = max_intensity_indices[len(max_intensity_indices) // 2]
        else:
            max_intensity_index = max_intensity_indices[0]

        max_intensity_index = max_intensity_index[0]

        if max_intensity_index - 1 < 0:
            left_from_max_intensity = max_intensity
        else:
            left_from_max_intensity = row[max_intensity_index - 1]
        if max_intensity_index + 1 == len(row):
            right_from_max_intensity = max_intensity
        else:
            right_from_max_intensity = row[max_intensity_index + 1]
        intensity_vec = np.array([left_from_max_intensity, max_intensity, right_from_max_intensity])

        if intensity_vec[0] == intensity_vec[1] == intensity_vec[2]:
            x_coord = max_intensity_index
        else:
            abc = np.linalg.solve(mat, intensity_vec)
            # calculate zero crossing
            # 0 = 2a * i + b
            # -->
            # i = -b / 2a
            deviation_from_middle = (-1 * abc[1]) / (2 * abc[0])
            x_coord = deviation_from_middle + max_intensity_index

        x = np.append(x, x_coord)
        y = np.append(y, row_index)
        row_index += 1

    z = np.ones(len(x))

    return np.array((x, y, z))


class LaserLine:

    def __init__(self, rvec=np.array([]), tvec=np.array([]), original_img=None, img_with_laser=None, threshold=15,
                 mask=None):
        assert type(threshold) == int, "Threshold should be an integer!"

        if original_img is not None:
            assert img_with_laser is not None, "Both images should be passed!"

            # original_img = cv.imread(f'../data/images/input/{original_img}.png')
            assert original_img is not None, "Image at 'original_img' could not be loaded!"
            # img_with_laser = cv.imread(f'../data/images/input/{img_with_laser}.png')
            assert img_with_laser is not None, "Image at 'img_with_laser' could not be loaded!"

            if mask is not None:
                # If a mask is passed use bitwise-and
                original_img = cv.bitwise_and(original_img, original_img, mask=mask)
                img_with_laser = cv.bitwise_and(img_with_laser, img_with_laser, mask=mask)

            self.__img_laser = cv.subtract(img_with_laser, original_img)
            self.__laser_points = get_line_pixels(self.__img_laser)

            # only for debug-information
            # self.display_laser_line()
        else:
            self.__img_laser = None
            self.__laser_points = np.array([])

        self.__rvec = rvec
        self.__tvec = tvec

    def get_laser_points(self):
        assert len(self.__laser_points) != 0, "Warning! Laser_Line is empty!"

        return self.__laser_points

    def get_rvec(self):
        assert len(self.__rvec) != 0, "Warning! Laser_Line is empty!"

        return self.__rvec

    def get_tvec(self):
        assert len(self.__tvec) != 0, "Warning! Laser_Line is empty!"

        return self.__tvec

    def display_laser_line(self):
        assert len(self.__img_laser) is not None, "Warning! Laser_Line is empty!"

        cv.imshow("Laser Line", self.__img_laser)
        cv.waitKey(0)
