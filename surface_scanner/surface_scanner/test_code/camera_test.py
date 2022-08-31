import cv2 as cv
import sys
import RPi.GPIO as GPIO
import time
import numpy as np


def getLaserImages():

        pin = 11
        GPIO.setmode(GPIO.BOARD)
        GPIO.setup(pin, GPIO.OUT)

        origin_img = take_one_pic()

        GPIO.output(pin, True)
        time.sleep(0.05)
        
        laser_img = take_one_pic()

        GPIO.output(pin, False)
        GPIO.cleanup()
        return np.array([origin_img, laser_img])


def take_one_pic():
        cam = cv.VideoCapture(0)

        ret, frame = cam.read()
        if ret:
                origin_img = frame
                
        cam.release()

        return origin_img
'''cap = cv2.VideoCapture(0)

# Capture frame
ret, frame = cap.read()
if ret:
        r = cv2.imwrite('/home/tristan/Dokumente/Bilder/image1.jpg', frame)
        print(f"returned: {r}")
        # print(sys.path)
cap.release()'''



images = getLaserImages()

cv.imwrite('/home/tristan/Dokumente/Bilder/origin_img.jpg', images[0])
cv.imwrite('/home/tristan/Dokumente/Bilder/laser_img.jpg', images[1])