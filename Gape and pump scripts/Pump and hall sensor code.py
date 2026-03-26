import serial #import pyserial not serial!!
import time
import datetime

pump_arduino_port = "COMX"  # Serial port of Arduino controlling pumps
sensor_arduino_port = "COMY"  # Serial port of Arduino with analog sensors
baud = 9600  # Baud rate
combined_file_name = "TEST.csv"  # Name of the combined CSV file

pump_ser = serial.Serial(pump_arduino_port, baud)
sensor_ser = serial.Serial(sensor_arduino_port, baud)

# Open the file in append mode, create it if it doesn't exist
with open(combined_file_name, "a") as combined_file:
    # Print column headers if the file is empty
    if combined_file.tell() == 0:
        combined_file.write("Datetime,PumpStatus,Sensor1,Sensor2,Sensor3,Sensor4,Sensor5,Sensor6,Sensor7,Sensor8,Sensor9,Sensor10,Sensor11,Sensor12,Sensor13,Sensor14,Sensor15,Sensor16\n")
        
    time.sleep(5)
    while True:
        # Get the current date and time
        time_stamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        # Turn on pumps
        pump_ser.write(b'1')
        print(f"{time_stamp} Pumps ON")


        # Read and log sensor data for x seconds (pump on time)
        start_time = time.time()
        while time.time() - start_time < 600: # change to number of seconds pump on
            time_stamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            sensor_data = str(sensor_ser.readline())
            sensor_reading = sensor_data[0:][:-2]
            sensor_reading2 = sensor_reading.replace("b\'", "")
            sensor_reading3 = sensor_reading2.replace("\\r\\", "")
            combined_file.write(f"{time_stamp},ON,{sensor_reading3}\n")
            print(f"{time_stamp},ON,{sensor_reading3}\n")
            time.sleep(1)  # Wait for 1 second

        # Turn off pumps
        time_stamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        pump_ser.write(b'0')
        print(f"{time_stamp} Pumps OFF")


        # Read and log sensor data for x seconds (pump off time)
        start_time = time.time()
        while time.time() - start_time < 3000: # change to number of seconds pump off
            time_stamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            sensor_data = str(sensor_ser.readline())
            sensor_reading = sensor_data[0:][:-2]
            sensor_reading2 = sensor_reading.replace("b\'", "")
            sensor_reading3 = sensor_reading2.replace("\\r\\", "")
            combined_file.write(f"{time_stamp},OFF,{sensor_reading3}\n")
            print(f"{time_stamp},OFF,{sensor_reading3}\n")
            time.sleep(1)  # Wait for 1 second



