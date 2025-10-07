# ☕ Proyecto de domotización de la cafetera Dolce Gusto del Makespace

Este proyecto tiene como objetivo **domotizar una cafetera de cápsulas Nescafé Dolce Gusto de Krups**.  
En concreto, se pretende:

- 🔸 Automatizar el **tiempo de dispensación del café**.  
- 🔸 Automatizar el **encendido y apagado** cuando la máquina permanezca inactiva.

---

## Cómo hacerse un café

Para preparar un café, sigue estos pasos:

1. **Enciende la máquina** mediante el botón lateral derecho con las marcas `0/I`.  
   La posición `I` indica que la máquina está encendida.
2. **Coloca la cápsula** en su soporte y ciérralo correctamente.  
3. **Espera** a que el **LED verde** situado encima del soporte deje de parpadear y se mantenga fijo.  
4. **Pulsa una vez el botón amarillo**, situado junto al botón de encendido/apagado general (`0/I`).

---

## Funcionamiento de la domotización

Después de realizar las cuatro operaciones anteriores, la máquina **suministra agua caliente** a través de la cápsula durante **20 segundos**. ¡Tenemos café!

- Si se vuelve a pulsar el **botón amarillo** durante este proceso, la máquina **detiene inmediatamente** la dispensación de agua (modo de parada de emergencia).  
- Al volver a pulsarlo, **reanuda la operación** durante otros 20 segundos.

Además:

- Si transcurren **dos minutos sin pulsar el botón amarillo**, la máquina **desconecta el calderín**, aunque **no se apaga por completo**. Por ello, **es importante dejar el botón lateral en la posición `0`** cuando no se vaya a utilizar.

---

## Explicación sencilla del circuito

Al conectar la máquina a la corriente y colocar el botón de encendido en la posición `I`, se genera un voltaje de 5 V.  
Este voltaje pasa por un diodo (para evitar inversiones de polaridad) y alimenta los siguientes componentes:

-  **ESP8266**
-  **Dos relés**, que controlan:
  - El **calderín** (pin D3)
  - La **bomba de agua** (pin D4)
- **Un botón**, conectado con una resistencia de **10 kΩ** en configuración *pull-up* al pin D2.
- **Un sensor NTC**, conectado como divisor de tensión con una resistencia de **100 kΩ** al pin A0.  
  El divisor se alimenta con **3,3 V** procedentes del propio ESP8266.

---

### Proceso de funcionamiento

1. Al encender la máquina, el **calderín comienza a calentarse** hasta alcanzar una temperatura aproximada de **60 °C a 70 °C**.  
   (Se supone que el circuito original incluye alguna protección, como un **fusible térmico**, para cortar la corriente al calderín en caso de sobrecalentamiento).

2. Mientras tanto, el ESP8266 permanece a la espera de que se pulse el botón amarillo (una vez la cápsula esté colocada y el LED verde se mantenga fijo).

3. Al pulsar el botón:
   - El ESP8266 lee la temperatura mediante el NTC, que está en contacto con el calderín.  
   - Si la temperatura igual o supera los 60 °C, se activa el relé que controla la bomba de agua.

4. El relé de la bomba se mantiene cerrado durante 20 segundos, tiempo durante el cual la máquina dispensa agua caliente a través de la cápsula.

---

## Componentes principales

| Componente | Función | Pin del ESP8266 |
|-------------|----------|----------------|
| Relé 1 | Control del calderín | D3~0 |
| Relé 2 | Control de la bomba de agua | D4~2 |
| Botón amarillo | Activación de la dispensación | D2~4 |
| Sensor NTC | Lectura de temperatura del calderín | A0~A0 |

---

## 📜 ANÍMATE A SEGUIR CON EL PROYECTO

- 💡 Pon el funcionamiento las tiras LED que cubren la carcasa de la cafetera. ¿Qué tal si indicasen el tiempo de inactividad? ¿ o la temperatura?
- 💡 Conecta el ESP8266 a internet y avanza con la domotización

---


