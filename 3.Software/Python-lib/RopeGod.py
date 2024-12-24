import serial

def map_value(value, from_min, from_max, to_min, to_max):
    return int((value - from_min) * (to_max - to_min) / (from_max - from_min) + to_min)

def set_servo_position(index, angle, control_id, serial_port='/dev/ttyUSB0', baudrate=9600):
    angle_value = map_value(angle, 0.0, 180.0, 0, 2000)
    
    send_buf = bytearray(16)
    
    send_buf[0] = 0xAA
    send_buf[3] = 0x08
    send_buf[6] = control_id >> 8
    send_buf[7] = control_id & 0xFF
    send_buf[8] = 0x01
    send_buf[9] = index
    send_buf[10] = angle_value >> 8
    send_buf[11] = angle_value & 0xFF
    
    with serial.Serial(serial_port, baudrate) as ser:
        ser.write(send_buf)

set_servo_position(1, 90.0, 32)

# print(map_value(600, 0, 2000, 0, 180.0))
# print(map_value(1600, 0, 2000, 0, 180.0))

# print(map_value(900, 0, 2000, 0, 180.0))
# print(map_value(1260, 0, 2000, 0, 180.0))



""" note
index: The serial number used to control the motors
    0: Four-finger side sway
    1: Thumb side sway
    2: Thumb flexion
    3: Index finger flexion
    4: Middle finger flexion
    5: Ring finger flexion
    6: Little finger flexion
    
angle: 0 ~ 90, where 0 is the initial position
    For thumb side sway, the angle range is: 54 ~ 144
    For four-finger side sway, the angle range is: 81 ~ 113
    
control_id: CAN ID of the controller, default is 32
"""

