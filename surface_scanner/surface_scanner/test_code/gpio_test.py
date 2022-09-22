import RPi.GPIO as GPIO
import time

pin = 13
blink_delay = 0.5
laser_status = True

GPIO.setmode(GPIO.BOARD)
GPIO.setup(pin, GPIO.OUT)

try:
    while True:
        print(f"laser={str(laser_status)}")
        GPIO.output(pin, laser_status)
        laser_status = not laser_status
        time.sleep(blink_delay)
except:
    GPIO.cleanup()
    print("Finished!")