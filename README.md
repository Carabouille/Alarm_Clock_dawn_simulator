# Alarm_Clock_dawn_simulator
Hello I'm Carabouille a french guy who love tech and hardware and this is my GitHub to present you my project for Fallout !
I'm gonna present you my alarm clock with dawn simulator feature ! 

# The idea 
I often have trouble to wake up with my phone alarm, I often fell that I'm tired even though I slept a lot. And this is for a very simple reason our brain is not a machine he can't wake up so fast. He works in cycles. And our phone alarm get him off very fast of this cycle. A better way to wake up more naturally is whit the solar light (but the night I close the rolling shutter for the cold) So a solution to this issue is to use an alarm clocks with dawn simulator feature to increase the brightness of the room over the time to wake up your brain gently but problem : This type of alarm clocks is really expensive (over 100 euros) So I told myself thaht is the perfect occasion to create my own ALARM CLOCKS WITH DAWN SIMULATOR !!! And I'm gonna add a lot of features like : - local weather - Indoor temperature / humidity - Bedside lamp (to read the night) - Control all the Leds in my bedroom and more..... I really can't wait to start my project, develop my skills and learn so much ! I'm gonna give the best version of myself to be proud of my alarm clocks And I also hope that I will have the chance to go to Shenzen to meet other hardware fans ! Kind regards, your french friend, Florian "Carabouille" CHARLES :)) (be kink about my english I try to write this without translater ^^)

# Zine page 
The better way to desscribe my project is with a poster who talk about it ! 
I'm not a good designer but I think that I made a good poster

ET VOILA : 

<img src=Pictures/Zine_page_pic.jpg width="500"/>

The design idea is pretty simple the alarm clock in the center and some arrows to explain the different parts of the project
I explain here 7 features : 
- The oak log for the base
- All the PCB
- The touch screen
- The Zen river
- The light for the dawn simulator feature
- The switch on the top
- A battery (in case the electricty is shutting down)
- And the switchs and the potar on the side

My favourite color is the pink (hard to guess ^^)
I really love the cherry flower in the background that remind the cherry tree on the top of the alarm.
The UwU logo is everywhere cause with my friends it's a private joke since a few years.
I love the way that the "Fallout" goes behind the box.

Is not perfect of course but for my light skills in design I think it's really nice, I'm proud of it ! 


# CAD 
One of the main part of my project the CAD !
Fot this I used the software Solidworks ( a french soft! COCORICO!)
I'm in a toxic relationship with Solidworks sometime I love it, sometime I hate it...
This soft is not easy to use but after some crash and bug I finally made a CAD wich I'm proud of !

So for my project I had to work within certain constraints 

- a specfif screen size
- a way to difuse the light
- a heat sink for the light
- some buttons
- a battery
- a speaker
- a hole for the USB C port

And with all thats I need to find a good idea of design 

My first idea was a shape like the giant telescope like we can see in the American dessert.
But I have never obtain a result that I like

So I completly changed my idea to have a Zen garden on the top of my alarm clock
With a tree, plants and a river ! 

It looks like this : 

<img src=Pictures/box.png width="400"/>

yes that is not the same that on the zine page,
Solidworks is not really good to do rendenring

But all the parts are here and I even find it cool ! 
I really love that the PCB is not hide by all the case, it's cool to see it

On this picture we can see : the screen, the PCB, the UwU logo, the oak log and the buttons on the side

If we move to the top we can see the Zen garden 

<img src=Pictures/top_box.png width="400"/>

We can see :
- The hole on the top for the cherry tree
- The river on the front
- The switch to shut down the alarm
- The green is for the artificial moss
- and the servo motor

The servo motor is here to hide the light during the day with moss on it. And when is it the time to turn the light on the servo motor move the piece of plastic with moss on it that hide the light to let the light illuminate the room.
So the light system is invisible the day !

The servo motor is not hidden by the case cause the moss will recover it.

And on the switch I'll put a little japenese temple like we can see on the poster.

Let's make the walls transparent to see what there are inside the box !

<img src=Pictures/top_box2.png width="400"/>

<img src=Pictures/back_box.png width="400"/>


Yes there are a lot of things inside it ! 

We can see well on the first picture the servo motor as we saw earlier
And the light with the heat sink who is carry by a support fiw with screw to the box
The heat sink is necessary here cause the light need to be at least a 8W to diffuse a minimum of the light to wake you. 
But the light is also powered in 24V and if you do the calcul 

P = U * I

I = P / U

I = 8 / 24 = 0,33 A 

It's a lot for a little LED COB it can heat up to more than 100 degrees with the heat sink everything will be ok !

If we watch the second picture we can see the others components 

Like the speaker, even if the light is supposed to wake you. If you sleep very deep a good music is necessary to wake up ! 
We can see on the left the PCB buttons for all the buttons and the potar. Is link with the main PCB with a FPC cable.

The huge tank on the middle is for the water of the river. The pump is also inside. The holes are for the pipes.

We can see the USB C port in the bottom right also link with the main PCB with a FPC cable.

on the right we have the PCB for the SD card. And below it we have our battery.


And thats already a lot for a CAD but I'm really proud of me ! I can't wait to print it !



# PCB

OK so now it's the moment to talk about my PCB ! And it's a huge part of my project ! 
It's only my second PCB so it's not perfect, the first was the macropad.

<img src=Pictures/pcb_elec_1.png width="1000"/>

This is only the main PCB and I'm going to describe all the differetns part
I'm not gonna describe how I choosed the components because it's not really important, but fro each components I had follow the datasheet.

So we can see at the top left the port J1 that bring the power supply from the USB C port on an ohter PCB.
The power is send to the first components the MCP73871. This component charge at the same time the battery in 4,2V and supply the system with the 5V

But 5V is toot high for an ESP32 so we need to decrease it to 3,3V with the AMS1117-3.3.

For this project I used a ESP32-S3-WROOM-1 is very powerfull and the wifi connection will help me to search the local weather.









# Firmware

# BOM

# Special thanks
