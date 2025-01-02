# # reference for struct in python:
# # https://docs.python.org/3/library/struct.html
import struct

int_8_value = 123
int_16_value = 12345

int_8_packed_data = struct.pack('b', int_8_value)
int_16_packed_data = struct.pack('h', int_16_value)

unpacked_int_8_value = struct.unpack('b', int_8_packed_data)[0]
unpacked_int_16_value = struct.unpack('h', int_16_packed_data)[0]

print(f'Unpacked int_8 value: {unpacked_int_8_value}')
print(f'Size of int_8 value in bytes: {len(int_8_packed_data)}')

print(f'Unpacked int_16 value: {unpacked_int_16_value}')
print(f'Size of int_16 value in bytes: {len(int_16_packed_data)}')