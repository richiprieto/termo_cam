import cv2

camera = cv2.VideoCapture(0)

# Insertar la conexión serial con el hardware
# si se necesita debe solo tomar una foto, ahora es video continuo
# verificar si la bandera de activación la va a realizar el hardware o el software
# Realizar el bot de telegram

while True:
    return_value, image = camera.read()
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    cv2.imshow("foto", gray)
    if cv2.waitKey(1) & 0xFF == ord("q"):
        cv2.imwrite("fotos/prueba.jpg", image)
        break
camera.release()
cv2.destroyAllWindows()
