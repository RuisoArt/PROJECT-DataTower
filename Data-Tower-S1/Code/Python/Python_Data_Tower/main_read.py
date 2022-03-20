"""
El codigo base, con comentarios y explicaciones, esta en la carpeta "codigo_base_lectura" donde se toma la lectura de
los datos sensores de temperatura y corriente, junto con las respuestas del MCU.
"""

import serial
import time
import menus

object_lecturaArduino = serial.Serial("COM3", 9600)
time.sleep(1)

# def lectura_datos():
while True:
    val = object_lecturaArduino.readline()
    cadena_valores = val.decode('ascii')

    pos = cadena_valores.index(':')
    label = cadena_valores[:pos]
    value = cadena_valores[pos + 1:]

    if label == 'Ip':
        print("La corriente pico del sistema es: {}".format(value))
        current_pico_date = value
    elif label == 'Irms':
        print("la corriente RMS del sistema es: {}".format(value))
        current_irms_date = value
    elif label == 'P':
        print("La potencia en WATTS del sistema es: {}".format(value))
        power_date = value

    elif label == 'T1':
        print("La Temperatura del sensor 1 es: {}".format(value))
        temp_1_date = value
    elif label == 'T2':
        print("La Temperatura del sensor 2 es: {}".format(value))
        temp_2_date = value
    elif label == 'T3':
        print("La Temperatura del sensor 3 es: {}".format(value))
        temp_3_date = value
    elif label == 'T4':
        print("La Temperatura del sensor 4 es: {}".format(value))
        temp_4_date = value
    elif label == 'T5':
        print("La Temperatura del sensor 5 es: {}".format(value))
        temp_5_date = value
    elif label == 'T6':
        print("La Temperatura del sensor 6 es: {}".format(value))
        temp_6_date = value
    elif label == 'T7':
        print("La Temperatura del sensor 7 es: {}".format(value))
        temp_7_date = value
    elif label == 'T8':
        print("La Temperatura del sensor 8 es: {}".format(value))
        temp_8_date = value

    elif label == 'MCU N':
        print("El MCU recibio: {} |Este dato es erroneo CARAJO|".format(value))
        mcu_n_date = value
    elif label == 'MCU 0':
        print("El MCU recibio: {} |OFF|".format(value))
        mcu_zero_date = value
    elif label == 'MCU 1':
        print("El MCU recibio: {} |ON|".format(value))
        mcu_one_date = value
