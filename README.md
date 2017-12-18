# reine-performing-robots

My personal website documentation for revolver (including photographs and video): 

http://reine.co/reine-bot.html

Concept: What personality did you want to portray in your actor? How did you use technology to accomplish this?

I wanted my audience to be in a calmer, more meditative environment. I wanted them to watch my robot perform a pattern that absorbs attention. And I wanted this pattern to over time evolve into something new, as the performance went on. I was really interested in this idea of rotation, because it creates this level of fluidity, so it was clear early on that I wanted to make spinning wheels. The beauty of technology is, when engineered properly, it creates these stable patterns that can last and evolve without the necessity of direct human interaction (after the engineering part).

Discuss the materials and construction techniques. Why did you chose these? Knowing what you know now, would you have chosen different materials or techniques?

In the end, the aluminum and acryllic worked really well for being durable yet also flexible. I preferred using the aluminum because it was easy to drill into and proved to be a solid base to work off of for the remainder of the project. The clear acryllic added both a nice aesthetic, and the wall itself leaned over close enough so that the magnets on the wheels were able to spin the balls without the balls flying off mid-performance. The wooden platform was rather clunky and in the future I would likely consider a base that doesn't require so much space. The wood, however, was durable enough to hold up the central wheels and created a durable environment to work off of. The motors were strong enough to handle the weight. If anything, I would likely run 12V instead of 9V in the future for even more speed (my instructor James told me the motors can handle that voltage). The Neopixels were phenomenal to actually pinpoint a yellow-blue color scheme that my partner and I were able to work off of. All in all, there were almost no faults with the hardware, and if I were to recreate this project, I would likely replicate it using the same materials. One thought I did have would be to, instead of laser cutting clear acryllic wheels, instead have the motors spin long strips of aluminum, where the magnets and hardware would be attached.


What did you have to learn in order to complete your project? How did you learn this? (Include links to any useful resources)

Describe the electronic and electrical part of your project

In the last few days before the performance, my instructor taught me how to wire up gyroscopes to the Arduino MKR1000s, as a way of mapping a Neopixel light on the secondary wheels. You can view my code in /code/agnus-gyroscope folder. 

I used old code that I got from my instructor to create the Bluetooth connection on my Arduino, and from there coded simple motor responsivity to certain control buttons (also available in my /code/bluetooth folder). The soldering that I needed to do was solder the Neopixels and gyroscopes to wires which then attached to the MKR1000 boards, and then also solder the Bluetooth chip to the Motorshield/Arduino contraption, following these online guides: 

https://www.arduino.cc/en/Guide/MKR1000

https://github.com/michaelshiloh/motorShieldAndBluefruit


What were the 3 most difficult parts of your project?

- Finding a motor strong enough to actually spin the entire contraption. I was first using a 303 RPM motor which I had to first spin by hand to get it running. I then moved down to a 101, until finally sticking with a 40 RPM. This motor was slower, but guaranteed the strength needed to rotate the rest of the robot.

- Getting the wheels to actually spin the magnetic balls on the acryllic wall. I lost several magnetic balls in the process of finding the perfect distance between the wheels and the wall. It was especially tricky because the wheels weren't exactly vertical, so at times the magnets were farther or closer to the wall, risking the balls to fall off at certain points.

- Ensuring the secondary wheels were properlly strapped on to the primary, larger wheel. I used plumber's tape to wrap the motors around two metal brackets. I had to go back and screw these back in tighter periodically. In hindsight, this is not the most robust means for attaching motors, however as long as I checked on them every week or so, it was relatively durable. 

-----------------------------------------------------------------------------------

Older scheduling documentation:


DUE FOR NOVEMBER 16TH, THURSDAY:

- Begin illustrator files and finalize measurements for layer 2 of spinning robot arm 
- Meet with Arantza and finalize construction details, collaborate to make sure Software projections are in sync with hardware
- Finalize specific dimension intensions for robot project

- Be ready to start laser cutting in class on Thursday.

TO BE PRINTED:

- central Vinyl acryllic base
- two acryllic stands to hold both motors
- two acryllic CD bases for the two motor spins

- Gather the two light motors needed for the second arm.


DUE FOR NOVEMBER 21ST, TUESDAY:

- Finish second layer of robot arm and have started construction of initial layer (the heavier duty motor).
- Second layer should be robust and durable for application on to initial layer.


DUE FOR NOVEMBER 23RD, THURSDAY:

- Finish robot arm and be ready for trial runs for durability and management. Begin preparations for acrylic wall to go in front of arm. 


------------------------------------------

SOFTWARE ART/TEXT  - PERFORMING ROBOTICS COLLABORATION WEBSITE:



https://reine-performing-robotics.tumblr.com




This is the thorough description of our schedule, technicalities, materials, and sketches drawn in preparation of the December IM exhibition



-----------------------------------------

Robotic Performance: Huang Yi and Kuka


https://www.youtube.com/watch?v=7moBSpAEkD4

http://www.nyuad-artscenter.org/en_US/events/2016/huang-yi-and-kuka/

https://www.engineersaustralia.org.au/portal/news/dancing-robots


Huang Yi and his robot arm Kuka perform a perfectly timed theatrical dance. The performance is so precisely timed that it serves as a beautiful example for Hoffman's discussion that theater is a playground for learning how to sharpen the precision of robots and their coordination as performers. The robot takes on a character and is just as valuable as Yi during the performance - both move with each other seamlessely. I used to consider how we as humans are striving to make robots faster, but in this case, theater emphasizes that robots cannot be too fast either; rather, they must to some degree resemble humans while taking advantage of their extra capabilities of a robot. They must empathize with humans to integrate into the performance. But Kuka, for example, also employs a green lazer at times for Yi to dance around. The arm additionally is not designed to appear as anything other than a robotic arm. The robot's movements are, from David V. Lu's Ontology of Robot Theater, human-produced and open-looped - hard coded, organized, and specified prior to the dance. Yet though the robot does not create movements through algorithms (thus changing the performance), his job, in this performance, becomes less about the robot's independance, and more about timing, stylization, and how Yi can create fluidity with otherwise structured robotic arm movements.
