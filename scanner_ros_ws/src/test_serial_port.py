import serial
import time

SERIAL_CONNECTION = serial.Serial("/dev/ttyACM0", 115200)

home = open('/home/tristan/Praktikum/git/ros2_surface_scanner/scanner_ros_ws/src/home.gcode', 'r')
calibration_position = open('/home/tristan/Praktikum/git/ros2_surface_scanner/scanner_ros_ws/src/calibration_position.gcode', 'r')

in_bytes = '\r\n\r\n'.encode('utf-8')

SERIAL_CONNECTION.write(in_bytes)
time.sleep(2)
SERIAL_CONNECTION.flushInput()

SERIAL_CONNECTION.write('G91 \n'.encode('utf-8'))
SERIAL_CONNECTION.write('G28 \n'.encode('utf-8'))
SERIAL_CONNECTION.write('G1 Y150 F3000 \n'.encode('utf-8'))
time.sleep(18)
print(f'a')
time.sleep(2)
SERIAL_CONNECTION.write('G91 \n'.encode('utf-8'))
SERIAL_CONNECTION.write('G28 \n'.encode('utf-8'))

# for line in home:
#     l = line.strip()
#     print(f'sending: {l}')
#     SERIAL_CONNECTION.write((l + '\n').encode('utf-8'))
#     grbl_out = SERIAL_CONNECTION.readline()
#     print(f' : {grbl_out.strip()}')


# move.close()
home.close()
calibration_position.close()
SERIAL_CONNECTION.close()
