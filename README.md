# Proyecto para domotizar la cafetera Dolce Gusto del Makespace

Este proyecto tiene como objetivo domotizar una cafetera de cápsulas Nescafé Dolce Gusto de Krups. En concreto se pretende:

- Automatizar el tiempo que la máquina dispensará café.
- Automatizar el tiempo de encendido/apagado cuando la máquina esté inactiva.

## Funcionamiento

   Para poder hacerse un café es necesario realizar los siguientes pasos:
   
   1. Encender la máquina mediante el botón del lateral derecho con las marcas `0/I`, estando la máquina encendida en la posición ´I´.
   2. Cargar la cápsula en el soporte y cerrarlo.
   3. Esperar a que el LED verde situado encima del soporte no parpadee y se mantenga fijo.
   4. Pulsar una vez sobre el botón amarillo situado al lado del botón de encedido y apagado general de la máquina (0/I).

   Al realizar estas cuatro operaciones la máquina suministrará agua caliente a través de la cápsula durante 20 segundos. En caso de que se vuelva a pulsar el botón amarillo durante esta operación, la máquina dejará de dispensar agua. Se trata de una parada de emergencia, volviéndose a reanudar durante 20 segundos si se vuelve a pulsar el botón.
   
   Si transcurren dos minutos sin que se realice una pulsación al botón amarillo, la máquina desconectará su calderín, sin apagarse por completo, por lo que es importante que cuando no se vaya a usar, el botón lateral quede en la posición 0.
   
3. 
