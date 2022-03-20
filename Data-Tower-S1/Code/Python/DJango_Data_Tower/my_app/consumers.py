import json
from channels.generic.websocket import AsyncWebsocketConsumer
from random import randint
from asyncio import sleep

import serial
import time

class WSConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        await self.accept()

        object_lecturaArduino = serial.Serial("COM3", 9600)
        await sleep(1)

        temp_1_date = 0
        temp_2_date = 0
        temp_3_date = 0
        temp_4_date = 0
        temp_5_date = 0
        temp_6_date = 0
        temp_7_date = 0
        temp_8_date = 0
        current_pico_date = 0
        current_irms_date = 0
        power_date = 0

        for i in range(14400):

            val = object_lecturaArduino.readline()
            cadena_valores = val.decode('ascii')

            ##cadena_valores.replace("\r\n", "")
            nueva = cadena_valores.replace('\r\n','')
            #nueva = cadena_valores

            pos = nueva.index(',')
            label = nueva[:pos]
            trans = nueva[pos + 1:]
            value = float(trans)

            #randint(1, 100)


            if label == 'T1':
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

            elif label == 'Ip':
                print("La corriente pico del sistema es: {}".format(value))
                current_pico_date = value

            elif label == 'Irms':
                print("la corriente RMS del sistema es: {}".format(value))
                current_irms_date = value

            elif label == 'P':
                print("La potencia en WATTS del sistema es: {}".format(value))
                power_date = value
            else:
                print("excepcion")

            await self.send(json.dumps({
                'message': temp_1_date,
                #'message': randint(20, 30),

                'messageNi': temp_2_date,
                #"'messageNi': randint(20, 30),

                'messageSan': temp_3_date,
                #'messageSan': randint(20, 30),

                'messageYon': temp_4_date,
                #'messageYon': randint(20, 30),

                'messageGo': temp_5_date,
                #'messageGo': randint(20, 30),

                'messageRoku': temp_6_date,
                #'messageRoku': randint(20, 30),

                'messageNana': temp_7_date,
                #'messageNana': randint(20, 30),

                'messageHachi': temp_8_date,
                #'messageHachi': randint(20, 30),

                'messageKyu': current_pico_date,
                #'messageKyu': randint(20, 30),

                'messageJu': current_irms_date,
                #'messageJu': randint(20, 30),

                'messageJuichi': power_date,
                #'messageJuichi': randint(20, 30),
                #
            }))

            """
            # await self.send(json.dumps({'message': temp_1_date, }))
            await self.send(json.dumps({'message': randint(20, 30), }))
            # await self.send(json.dumps({ 'messageNi': temp_2_date, }))
            await self.send(json.dumps({'messageNi': randint(20, 30), }))
            # await self.send(json.dumps({ 'messageSan': temp_3_date, }))
            await self.send(json.dumps({'messageSan': randint(20, 30), }))
            # await self.send(json.dumps({ 'messageYon': temp_4_date, }))
            await self.send(json.dumps({'messageYon': randint(20, 30), }))
            # await self.send(json.dumps({ 'messageGo': temp_5_date, }))
            await self.send(json.dumps({'messageGo': randint(20, 30), }))
            # await self.send(json.dumps({ 'messageRoku': temp_6_date, }))
            await self.send(json.dumps({'messageRoku': randint(20, 30), }))
            # await self.send(json.dumps({ 'messageNana': temp_7_date, }))
            await self.send(json.dumps({'messageNana': randint(20, 30), }))
            # await self.send(json.dumps({ 'messageHachi': temp_8_date , }))
            await self.send(json.dumps({'messageHachi': randint(20, 30), }))
            # await self.send(json.dumps({ 'messageKyu': current_pico_date, }))
            await self.send(json.dumps({'messageKyu': randint(20, 30), }))
            # await self.send(json.dumps({ 'messageJu': current_irms_date, }))
            await self.send(json.dumps({'messageJu': randint(20, 30), }))
            # await self.send(json.dumps({ 'messageJuichi': power_date, }))
            await self.send(json.dumps({'messageJuichi': randint(20, 30), }))
            """
            await sleep(0.25)

            """
            for i in range(14400):
                
                #Si son 14400 repeeticiones, cada una a 250ms, esto da un total de 3600 s de envio de datos, aproximadamente 1h
                
                # self.send(json.dumps(dict(message=randint(1, 100))))
                await self.send(json.dumps({
                    #'message': randint(1, 100),
                    #'messageNi': randint(1, 100),
                    #'messageSan': randint(1, 100),
                    #'messageYon': randint(1, 100),
                    #'messageGo': randint(1, 100),
                    #'messageRoku': randint(1, 100),
                    #'messageNana': randint(1, 100),
                    #'messageHachi': randint(1, 100),
                    #'messageKyu': randint(1, 100),
                    #'messageJu': randint(1, 100),
                    #'messageJuichi': randint(1, 100),
                }))
                
                
            """
            #await sleep()