import cv2
import sys

cap = cv2.VideoCapture(0)

# Capture frame
ret, frame = cap.read()
if ret:
        r = cv2.imwrite('/home/tristan/Dokumente/Bilder/image1.jpg', frame)
        print(f"returned: {r}")
        # print(sys.path)
cap.release()