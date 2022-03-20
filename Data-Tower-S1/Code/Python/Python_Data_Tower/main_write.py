import serial
import time
import menus

accion_moc = 0
teclado = ""

lectura_MCU = serial.Serial("COM3",9600)
time.sleep(1)

#def escritura_datos():
while True:
    contenedor = lectura_MCU.readline()
    trama_de_datos = contenedor.decode('ascii')

    pos = trama_de_datos.index(":")
    label = trama_de_datos[:pos]
    value = trama_de_datos[pos + 1:]

    menus.show_menu()  # mostrar menu de ingreso

    teclado = input('Escriba el numero de la opcion que necesita: ')

    if teclado == 'x':
        print("\n<-----Close Write----->\n")
        break

    elif teclado == '1':
        accion_moc = 1
        send = str(accion_moc)
        lectura_MCU.write(send.encode('ascii'))
        print("\n<-----Dato enviado ON----->\n")
    elif teclado == '0':
        accion_moc = 0
        send = str(accion_moc)
        lectura_MCU.write(send.encode('ascii'))
        print("\n<-----Dato enviado OFF----->\n")
    else:
        print("\n<-----dato erroneo----->\n")
