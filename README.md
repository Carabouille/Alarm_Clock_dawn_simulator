# Alarm_Clock_dawn_simulator
Hello, I'm Carabouille, a French guy who loves tech and hardware, and this is my GitHub to present you my project for Fallout!
I'm gonna present you my alarm clock with dawn simulator feature!

# The idea 
I often have trouble waking up with my phone alarm. I often feel that I'm tired even though I slept a lot. And this is for a very simple reason: our brain is not a machine; he can't wake up so fast. He works on cycles. And our phone alarm gets him off very fast during this cycle. A better way to wake up more naturally is with the solar light (but the night I close the rolling shutter for the cold). So a solution to this issue is to use an alarm clocker with a dawn simulator feature to increase the brightness of the room over time to wake up your brain gently, but problem : Tis type of alarm clocks is really expensive (over 100 euros), so I told myself that it is the perfect occasion to create my own ALARM CLOCKS WITH A DAWN SIMULATOR!!! And I'm gonna add a lot of features like: 
- local weather
- Indoor temperature / humidity
- Bedside lamp (to read the night)
- Control all the Leds in my bedroom
- and more.....

I really can't wait to build my project, develop my skills and learn so much! I'm gonna give the best version of myself to be proud of my alarm clocks and I also hope that I will have the chance to go to Shenzen to meet other hardware fans! Kind regards, your French friend, Florian "Carabouille" CHARLES :))

# Zine page 
The better way to describe my project is with a poster who talks about it! 
I'm not a good designer, but I think that I made a good poster

ET VOILA : 

<img src=Pictures/Zine_page_pic.jpg width="500"/>

The design idea is pretty simple: the alarm clock in the center and some arrows to explain the different parts of the project
I explain here 7 features: 
- The oak log for the base
- All the PCBs
- The touch screen
- The Zen river
- The light for the dawn simulator feature
- The switch on the top
- And the switches and the knob on the side

My favourite color is the pink (hard to guess ^^)
I really love the cherry flower in the background that reminds me of the cherry tree on the top of the alarm.
The UwU logo is everywhere cause with my friends it's a private joke since a few years.
I love the way that the "Fallout" goes behind the box.

Is not perfect of course but for my light skills in design I think it's really nice, I'm proud of it ! 


# CAD 
One of the main parts of my project is the CAD!
For this I used the software Solidworks ( a French soft! COCORICO!)
I'm in a toxic relationship with Solidworks, sometimes I love it, sometimes I hate it...
This software is not easy to use but after some crashes and bugs I finally made a CAD which I'm proud of!

So for my project I had to work within certain constraints 

- a specific screen size
- a way to diffuse the light
- a heat sink for the light
- some buttons
- a battery
- a speaker
- a hole for the USB C port

And with all that, I need to find a good idea for design

My first idea was a shape like the giant telescope, like we can see in the American desert.
But I have never obtained a result that I like

So I completely changed my idea to have a Zen garden on the top of my alarm clock
With a tree, plants, and a river!

It looks like this : 

<img src=Pictures/box.png width="400"/>

yes that is not the same as on the zine page,
Solidworks is not really good at rendering

But all the parts are here and I even find it cool! 
I really love that the PCB is not hidden by all the cases, it's cool to see it

On this picture we can see : the screen, the PCB, the UwU logo, the oak log and the buttons on the side

If we move to the top we can see the Zen garden 

<img src=Pictures/top_box.png width="400"/>

We can see :
- The hole on the top, for the cherry tree
- The river on the front
- The switch to shut down the alarm
- The green is for the artificial moss
- and the servo motor

The servo motor is here to hide the light during the day with moss on it. And when is it the time to turn the light on the servo motor move the piece of plastic with moss on it that hides the light to let the light illuminate the room.
So the light system is invisible during the day!

The servo motor is not hidden by the case cause the moss will recover it.

And on the switch I'll put a little Japanese temple like we can see on the poster.

Let's make the walls transparent to see what is inside the box!

<img src=Pictures/top_box2.png width="400"/>

<img src=Pictures/back_box.png width="400"/>


Yes, there are a lot of things inside it! 

We can see well in the first picture the servo motor as we saw earlier
And the light with the heat sink, which is carried by a support with screws to the box
The heat sink is necessary here cause the light needs to be at least a 8W to diffuse a minimum of the light to wake you. 
But the light is also powered on 24V and if you do the calcul

P = U * I

I = P / U

I = 8 / 24 = 0,33 A 

It's a lot for a little LED COB ! It can heat up to more than 100 degrees. With the heat sink, everything will be ok!

If we watch the second picture we can see the other components

Like the speaker, even if the light is supposed to wake you. If you sleep very deeply, good music is necessary to wake up! 
We can see on the left the PCB buttons for all the buttons and the knob. Is linked with the main PCB with a FPC cable.

The huge tank in the middle is for the water of the river. The pump is also inside. The holes are for the pipes.

We can see the USB C port in the bottom right also linked with the main PCB with a FPC cable.

On the right we have the PCB for the SD card. And below it we have our battery.
The battery is just in case that there is a power cut at home, the battery will supply the system until the return of power !

And that's already a lot for a CAD, but I'm really proud of me! I can't wait to print it!



# PCB

OK so now it's the moment to talk about my PCB! And it's a huge part of my project! 
It's only my second PCB so it's not perfect, the first was the macropad.

<img src=Pictures/pcb_elec_1.png width="1000"/>

This is only the main PCB, and I'm going to describe all the different parts
I'm not gonna describe how I chose the components because it's not really important, but for each component I had to follow the datasheet.

So we can see at the top left the port J1 that brings the power supply from the USB C port on an other PCB.
The power is sent to the first components the MCP73871. This component charge at the same time the battery in 4,2V and supplies the system with the 5V

But 5V is too high for an ESP32, so we need to decrease it to 3,3V with the AMS1117-3.3.

For this project I used an ESP32-S3-WROOM-1 that is very powerful and the WiFi connection will help me to search for the local weather.

For the speaker, we need to use an audio amplifier. I chose to use the MAX98357A, which is very famous for this type of project

I used a DW01A and a FS8205A, this duo of components is for the battery. To avoid overload, deep discharge, and protection from the short circuit.

For the LED and the fan of the heat sink I need 24V and 12V. So I used a 2 MT3608 to increase the voltage.

To control the led I'll use 2 channels of PWM to manage the warm and cold colors of the led.
To do this I'm gonna use a 2 transistors A03400A.

I also use a VEML770 a light sensor to manage the luminosity of the screen.

We also have a lot of connectors for the : 
- Screen
- USB C
- Heat sink
- Led COB
- Led strip (to decorate)
- servo motor
- SD card PCB
- Buttons PCB
- Battery

And after having done the wiring diagram, it's time to root all the components between them! 

This is my final solution:

<img src=Pictures/pcb_pcb_1.png width="1000"/>

<img src=Pictures/pcb_pcb_2.png width="500"/>
<img src=Pictures/pcb_pcb_3.png width="500"/>

We can see here all the components which I mentioned earlier
I root on 2 faces so it's not too difficult to do it. The main difficulty is to match the footprint with the real component.

And that's all for the main PCB. It's already a lot!



Let's talk about the second PCB, The Buttons PCB!! 

This PCB is simpler than the previous one, it is just a little repetitive with all the buttons 
We can see here the wiring diagram!

<img src=Pictures/pcb_elec_2.png width="1000"/>

You can see here 4 different PCBs separated by the blue lines.
The larger is the PCB with all the buttons and the polar.
Also, I used a MCP23017 to increase the number of pins GPIO of the ESP32 ( I used a lot of buttons ^^) I'll go into detail in the firmware part. 
You can see a capacitor in parallel for each button. It's anti-bounce material. It's very important for a professional project!
I added on this PCB an AHT 20, it's a temperature and humidity sensor.

The little PCB in the middle is for the switch on the top of the box.

The PCB on the bottom is the micro SD port card PCB

and the last is the PCB for the USB C

And after this it's rooting time ! 

<img src=Pictures/pcb_pcb_4.png width="1000"/>

<img src=Pictures/pcb_pcb_5.png width="500"/>

<img src=Pictures/pcb_pcb_6.png width="500"/>

That wasn't possible with the dimensions I needed to avoid the waste of some part of the PCB, like you can see the part not used.
I'm gonna cut the different PCB myself with a dremel.


# Firmware
The Firmware is a big part of my project! (I said it for each part ;-;)
To code I used the software Visual Studio Code and the extension Plateformio
The code is pretty simple for the moment. I only initialize all the components. I'm gonna add all the interesting features when I could have the card in my hands.
For the moment, given that I only initialize the components, all my code parts are just from the example code that I found online and from old code that I made.

In the code I initialize :
- The I2C bus
- The audio amplifier
- The SD card
- The screen
- The wifi connection (to obtain the hour, date and more soon)
- All the buttons with the MCP23017
- Servo motor
- the EC11
- The signal PWM for the LED
- The dislay of the hours on the screen
- The enable pin for the MT3608
- The VEML7700
- The AHT20

There are still a lot of things to add. I will add this later (with components in front of me) cause it is code more complicated, and it's useless to code this without debugging in live (I guess)

The things that I need to add: 
- A good design of the hours, temperatures, etc...
- alarm features (with the dawn simulator)
- all the buttons feature like :
- - turn on the smart plug of my computer
  - play a ACNL music
  - a sleep mode
  - song chill
  - bedside lamp
  - nap timer
  - switch that shuts down the alarm
  - set alarm 1
  - set alarm 2
  - turn on the leds of my room
  - turn on the river
  - the other buttons will be there to adjust certain settings



# BOM

Now it's the time to do the BOM and order all our components! 

I split the BOM into different parts.

The first part is the components that I'm going to order on LCSC (Overall, these are the CMD components)

| Components LCSC :               | name                    | value           | Quantity | LCSC code / link        | price (€) |                                  |
|---------------------------------|-------------------------|-----------------|----------|-------------------------|-----------|----------------------------------|
|                                 | Resistance              | 100             | 1        | [C105588](https://www.lcsc.com/product-detail/C105588.html)            | 0.13      |       X                          |
|                                 |                         | 300             | 1        | [C2930092](https://www.lcsc.com/product-detail/C2930092.html)          | 0.12      | X                                |
|                                 |                         | 5,1k            | 2        | [C2907044](https://www.lcsc.com/product-detail/C2907044.html)                | 0.11      |       X                          |
|                                 |                         | 1M              | 1        | [C2907115](https://www.lcsc.com/product-detail/C2907115.html)                | 0.08      |    X                             |
|                                 |                         | 10k             | 11       | [C98220](https://www.lcsc.com/product-detail/C98220.html)                  | 0.28      |    X                             |
|                                 |                         | 180k            | 1        | [C2906999](https://www.lcsc.com/product-detail/C2906999.html)                | 0.1       |    X                             |
|                                 |                         | 1k              | 5        | [C22548](https://www.lcsc.com/product-detail/C22548.html)                  | 0.14      |    X                             |
|                                 |                         | 390k            | 1        | [C137735](https://www.lcsc.com/product-detail/C137735)                 | 0.15      |    X                             |
|                                 |                         | 2,2k            | 2        | [C4190](https://www.lcsc.com/product-detail/C4190.html)                   | 0.14      |    X                             |
|                                 | Capacitor               | 10n             | 2        | [C100042](https://www.lcsc.com/product-detail/C100042.html)                 | 0.23      |    X                             |
|                                 |                         | 100n            | 26       | [C14663](https://www.lcsc.com/product-detail/C14663.html)                  | 0.56      |    X                             |
|                                 |                         | 10u             | 4        | [C440198](https://www.lcsc.com/product-detail/C440198.html)                 | 1.27      |    X                             |
|                                 |                         | 1u              | 1        | [C28323](https://www.lcsc.com/product-detail/C28323.html)                  | 0.24      |    X                             |
|                                 |                         | 22u             | 5        | [C342620](https://www.lcsc.com/product-detail/C342620.html)                 | 2.1       |    X                             |
|                                 |                         | 4,7u            | 2        | [C98192](https://www.lcsc.com/product-detail/C98192.html)                  | 0.18      |    X                             |
|                                 | VEML7700-TT             | X               | 1        | [C1850416](https://www.lcsc.com/product-detail/C1850416.html)                | 1.49      |    X                             |
|                                 | FS8205A                 | X               | 1        | [C2830320](https://www.lcsc.com/product-detail/C2830320.html)                | 0.52      |    X                             |
|                                 | YLED0603B (led)         | Blue            | 1        | [C19171394](https://www.lcsc.com/product-detail/C19171394.html)               | 0.54      |    X                             |
|                                 | YLED0603G (led)         | Green           | 1        | [C19273151](https://www.lcsc.com/product-detail/C19273151.html)               | 0.54      |    X                             |
|                                 | KT-0603R (led)          | Red             | 1        | [C2286](https://www.lcsc.com/product-detail/C2286.html)                   | 0.59      |    X                             |
|                                 | MAX98357AETE+T          | X               | 1        | [C910544](https://www.lcsc.com/product-detail/C910544.html)                 | 1.24      |    X                             |
|                                 | MCP73871-2AAI/ML        | X               | 1        | [C144351](https://www.lcsc.com/product-detail/C144351.html)                 | 2.74      |    X                             |
|                                 | MT3608                  | X               | 2        | [C84817](https://www.lcsc.com/product-detail/C84817.html)                  | 0.69      |    X                             |
|                                 | SS14 (diode)            | X               | 2        | [C2837270](https://www.lcsc.com/product-detail/C2837270.html)                | 0.48      |    X                             |
|                                 | AHT20                   | X               | 1        | [C2757850](https://www.lcsc.com/product-detail/C2757850.html)                | 0.58      |    X                             |
|                                 | MCP23017T-E/ML          | X               | 1        | [C629439](https://www.lcsc.com/product-detail/C629439.html)                 | 1.46      |    X                             |
|                                 | micro sd card port      | X               | 1        | [C506790](https://www.lcsc.com/product-detail/C506790.html)                 | 3.66      |    X                             |
|                                 | USB-C port              | X               | 1        | [C2765186](https://www.lcsc.com/product-detail/C2765186.html)                | 1.17      |    X                             |
|                                 | DW01A                   | X               | 1        | [C351410](https://www.lcsc.com/product-detail/C351410.html)                 | 0.75      |    X                             |
|                                 | Coil                    | 22u             | 2        | [C2826664](https://www.lcsc.com/product-detail/C2826664.html)                | 0.64      |    X                             |
|                                 | AMS1117-3.3             | X               | 1        | [C6186](https://www.lcsc.com/product-detail/C6186.html)                   | 0.99      |    X                             |
|                                 | AO3400A                 | X               | 2        | [C20917](https://www.lcsc.com/product-detail/C20917.html)                  | 0.36      |    X                             |
|                                 | FFC / FPC connector 1mm | 8 pins          | 4        | [C262714](https://www.lcsc.com/product-detail/C262714.html)                 | 0.99      |    X                             |
|                                 |                         | 12 pins         | 2        | [C262718](https://www.lcsc.com/product-detail/C262718.html)                 | 1.1       |    X                             |
|                                 | ESP32-S3-WROOM-1        | X               | 1        | [C2913202](https://www.lcsc.com/product-detail/C2913202.html)                | 4.58      |    X                             |
|      Total                      |                         |                 |          |                         | 30.94     |    X                             |
|                                 |                         |                 |          |                         |           |    X                             |

The second part is for the other types of components like switch, pump, speaker, LED, etc...
For the moment, it's only electronic components, all buy in Aliexpress

| Components LCSC :               | name                    | value           | Quantity | LCSC code / link        | price (€) |                                  |
|---------------------------------|-------------------------|-----------------|----------|-------------------------|-----------|----------------------------------|
| Others components (not in LCSC) | Switch push buttons     | 6mm.6mm.5.5mm   | 17       | [Link](https://fr.aliexpress.com/item/1005001629177989.html)                    | 1.22      |                                  |
|                                 | EC11 rotary encoder     | X               | 1        | [Link](https://fr.aliexpress.com/item/1005003824684681.html)                    | 1.33      |                                  |
|                                 | Touch screen            | 4 inch          | 1        | [Link](https://fr.aliexpress.com/item/1005005791515997.html)                    | 14.39     |                                  |
|                                 | Speaker                 | 8 ohm           | 1        | [Link](https://fr.aliexpress.com/item/4000034945525.html)                    | 10.7      |                                  |
|                                 | keyboard switch         | X               | 1        | [Link](https://fr.aliexpress.com/item/1005006298192363.html)                     | 4.39      |                                  |
|                                 | Servo motor             | 180 degrees     | 1        | [Link](https://fr.aliexpress.com/item/1005006572297006.html)                      | 2.7       |                                  |
|                                 | LED COB                 | 24V 8W          | 1        | [Link](https://fr.aliexpress.com/item/1005006373977700.html)                      | 1.89      |        X                         |
|                                 | Heat sink               | with fan 12V    | 1        | [Link](https://fr.aliexpress.com/item/1005003605697738.html)                      | 3.19      |                                  |
|                                 | Male pins               | 17 pins         | 1        | [Link](https://fr.aliexpress.com/item/4000873858801.html)                      | 1.89      |     X                            |
|                                 | Female pins             | 14 pins         | 1        |                         |           |      X                           |
|                                 | Battery                 | 18650           | 1        | [Link](https://fr.aliexpress.com/item/1005008704468583.html)                      | 6.59      |                                  |
|                                 | Led strip               | addressable 1m  | 1        | [Link](https://fr.aliexpress.com/item/1005009613294814.html)                      | 4.99      |                                  |
|                                 | 3D-printed insert       | M3              | 12       | [Link](https://fr.aliexpress.com/item/1005007653131713.html)                      | 1.69      |                                  |
|                                 | Screw                   | M3              | 12       | [Link](https://fr.aliexpress.com/item/32968616563.html)                      | 1.4       |                                  |
|                                 | Micro SD card           | 4go             | 1        | [Link](https://fr.aliexpress.com/item/1005008059516973.html)                      | 3.29      |                                  |
|                                 | FPC cable               | 12pins 15cm 1mm | 1        | [Link](https://fr.aliexpress.com/item/1005007561337665.html)                      | 1.72      |        X                         |
|                                 |                         | 8pins 10cm 1mm  | 2        | [Link](https://fr.aliexpress.com/item/1005007561337665.html)                      | 2.18      |        X                         |
|                                 | epoxy resin             | 50ml + 50ml     | 1        | [Link](https://fr.aliexpress.com/item/1005007345256355.html)                      | 6.59      |        X                         |
|                                 | Water pump              | 5V              | 1        | [Link](https://fr.aliexpress.com/item/1005006614378374.html)                      | 1.69      |        X                         |
|                                 | Pipe                    | 1m              | 1        | [Link](https://fr.aliexpress.com/item/1005006614378374.html)                      | 1.81      |        X                         |
|                     Total       |                         |                 |          |                         | 73.65     |                                  |
|                                 |                         |                 |          |                         |           |                                  |


In this last part we have the PCB, and all the elements of decoration 

| Components LCSC :               | name                    | value           | Quantity | LCSC code / link        | price (€) |                                  |
|---------------------------------|-------------------------|-----------------|----------|-------------------------|-----------|----------------------------------|
| PCB (JLCPCB)                    | Main PCB                | X               | 1        | Upload GERBER on JLCPCB | 3.4       | X                                |
|                                 | Buttons PCB             | X               | 1        |                         | 3.4       |  X                               |
|                                 |                         |                 |          |                         |           |                                X |
| Décoration                      | Log (for the base)      | 14-16cm         | 2        | [Link](https://fr.aliexpress.com/item/1005007635992230.html)                      | 9.78      |                                X |
|                                 | Temple                  | X               | 1        | [Link](https://fr.aliexpress.com/item/1005007500230985.html)                      | 2.1       |                                X |
|                                 | Moss 1                  | 20g             | 1        | [Link](https://fr.aliexpress.com/item/1005005026348059.html)                      | 1.72      |                                X |
|                                 | Moss 2                  | 20g             | 1        | [Link](https://fr.aliexpress.com/item/1005005026348059.html)                      | 2.04      |                                X |
|                                 | Cherry tree             | X               | 1        | [Link](https://fr.aliexpress.com/item/1005003593401791.html)                      | 3.89      |                                X |
|                                 | PLA black + white       | 1kg + 1kg       | 1        | [Link](https://www.amazon.fr/gp/product/B0CV4V5L7T/ref=ewc_pr_img_1?smid=AKWYTSYUMR87P&th=1)                      | 20.12     |                                X |
|                                 | Bridge                  | X               | 1        | [Link](https://fr.aliexpress.com/item/1005003493992894.html)                      | 1.05      |                                X |
|                  Total          |                         |                 |          |                         | 42.7      |                                  |
|                                 |                         |                 |          |                         |           |                                  |
|                                 |                         |                 |          |                         |           |                                  |
| Full price                      | 152.39                  |                 |          |                         |           |                                  |
| Real price                      | 96.51                   |                 |          |                         |           |                                  |
|                                 |                         |                 |          |                         |           |                                  |
| Aliexpress                      | 38.35                   |                 |          |                         |           |                                  |
| LCSC                            | 30.94                   |                 |          |                         |           |                                  |
| Amazon                          | 20.12                   |                 |          |                         |           |                                  |
| JLCPCB                          | 6,8                     |                 |          |                         |           |                                  |



So the total for all this is 150,39€ (176,19$)


But have you noticed that I've highlighted some prices in green?
Because I already have some components, I don't need to buy all this a second time.
So for me the total is: 94,51€ (110,72$)

To click on the link and see more details you can dowload the Excel BOM in the files ! 


# Special thanks

I want to thank my friend Pylou (love u my boy) for introducing me to the project !!

thanks to the HackClub / Fallout community the goatest community 

thanks to my mum for creating me

Thanks to photosynthesis for creating the oxygen that I breathe

Thanks to the reviewer !! I know the project is not easy to understand ;-; 

Thanks to Soup for the free koi with the streak ! 

I really hope you will enjoy it and I really hope I'll see you in Shenzhen ^^
