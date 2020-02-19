import pyfirmata
import time

board = pyfirmata.Arduino("/dev/ttyUSB0")

it = pyfirmata.util.Iterator(board)
it.start()

lightPin = board.get_pin("d:3:i")
buttonPin = board.get_pin("d:5:i")
magnetPin = board.get_pin("d:4:i")
soundPin = board.get_pin("d:6:i")

#prevLight = 0
prevButton = 0
prevMagnet = 0
prevSound = 0

while True:
    lightValue = lightPin.read()
    buttonValue = buttonPin.read()
    magnetValue = magnetPin.read()
    soundValue = soundPin.read()

    if prevButton != buttonValue:
        print("Button pressed!\n");
        print("Light value: "+lightValue+"\n");
        print("Button value: "+buttonValue+"\n");
        print("Magnet value: "+magnetValue+"\n");
        print("Sound value: "+soundValue+"\n\n");
        prevButton = buttonValue

    if prevMagnet != magnetValue:
        print("Magnet sensor triggered!\n");
        print("Light value: "+lightValue+"\n");
        print("Button value: "+buttonValue+"\n");
        print("Magnet value: "+magnetValue+"\n");
        print("Sound value: "+soundValue+"\n\n");
        prevMagnet = magnetValue

    if prevSound != soundValue:
        print("Sound detected!\n");
        print("Light value: "+lightValue+"\n");
        print("Button value: "+buttonValue+"\n");
        print("Magnet value: "+magnetValue+"\n");
        print("Sound value: "+soundValue+"\n\n");
        prevSound = soundValue

    time.sleep(100);
