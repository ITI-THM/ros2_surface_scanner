from pypylon import pylon
import time
import cv2 as cv
import numpy as np


class LaserCamera:

    def __init__(self):
        self._camera = pylon.InstantCamera(
            pylon.TlFactory.GetInstance().CreateFirstDevice())
        # pylon.FeaturePersistence.Load('/home/tristan/Praktikum/git/ros2_surface_scanner/scanner_ros_ws/src/a2A1920-160ucPRO_40151868.pfs', self._camera.GetNodeMap(), True)

        self._camera.RegisterConfiguration(pylon.SoftwareTriggerConfiguration(), pylon.RegistrationMode_ReplaceAll,
                                           pylon.Cleanup_Delete)
        print("Using device ", self._camera.GetDeviceInfo().GetModelName())

        self._camera.MaxNumBuffer = 5
        self._camera.Open()
        self._camera.StartGrabbing(pylon.GrabStrategy_OneByOne)

        # Activate GPIO of Line 2
        self._camera.LineSelector.SetValue("Line2")
        self._camera.LineMode.SetValue("Output")
        self._camera.LineSource.SetValue("UserOutput1")
        self._camera.LineInverter.SetValue(False)
        self._camera.UserOutputSelector.SetValue('UserOutput1')
        self._camera.UserOutputValue.SetValue(False)

        # Setup Image Converter
        self._converter = pylon.ImageFormatConverter()
        self._converter.OutputPixelFormat = pylon.PixelType_BGR8packed
        self._converter.OutputBitAlignment = pylon.OutputBitAlignment_MsbAligned

    def __del__(self):
        self._camera.StopGrabbing()
        self._camera.Close()
        cv.destroyAllWindows()

    def showImages(self):
        images = self.getLaserImages()

        img_diff = cv.subtract(images[1], images[0])

        cv.imshow("origin_img", images[0])
        cv.imshow("laser_img", images[1])
        cv.imshow("diff", img_diff)
        cv.imshow("diff_grey", cv.cvtColor(img_diff , cv.COLOR_BGR2GRAY))

    def getLaserImages(self):
        self._camera.UserOutputValue.SetValue(False)
        time.sleep(0.05)
        for i in range(2):
            if self._camera.WaitForFrameTriggerReady(200, pylon.TimeoutHandling_ThrowException):
                if i > 0:
                    self._camera.UserOutputValue.SetValue(True)
                self._camera.ExecuteSoftwareTrigger()
                time.sleep(0.1)
                print("Line Value: ", self._camera.LineStatus.GetValue())

        self._camera.UserOutputValue.SetValue(False)

        time.sleep(0.2)

        if self._camera.GetGrabResultWaitObject().Wait(0):
            print("Grab results wait in the output queue.")

        images = []
        for i in range(2):
            result = self._camera.RetrieveResult(
                0, pylon.TimeoutHandling_Return)
            image = self._converter.Convert(result)
            images.append(image.GetArray())

        return images


cam = LaserCamera()
cam.showImages()
cv.waitKey(0)
