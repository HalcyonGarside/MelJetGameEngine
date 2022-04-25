 ____________________________________
|                          ..   ..    |
        /|  /|       |     ----- .
       / | / |       |    ..*...
      /  |/  |el |___|et   ...
|____________________________________|

(aka TelKit, for reasons yet to be clear)

A custom game engine by William Blanchard

This game engine is being created as an ongoing exercise in computer graphics
software development, a field I am very curious about and wish to pursue.

This is the third or fourth time I have revived this project.  I continually come back to it whenever I get a new wind or come across a new mental approach.  It's been a year or two since I last worked on MelJet, and at the time I stopped work on it I was attempting to start of by writing... a rendering engine.  No debugging, no input, no CLI, nothing in terms of tools.  Just a 3D rendering engine right at the beginning of the development of an entire game engine with hardly a plan in mind.  I was also using C++, compiling with the MSVC compiler, didn't have any vision for a specific game I'd be making with it, and probably a variety of other sins that don't quite come to mind right at the moment.

Did I mention I'm in college?  I'm in college.

So here's my current approach with this project:

I'm keeping my previous master branch in a separate branch as a testament to my failure.  I feel like I can compare that to how I'm trying to begin my work right now in some form of screwed-up motivation.

I'm working on this project in pure C.  I've heard plenty of talks that talk about the importance of making your own tools and effectively having full control of your system to know that it would benefit me to not rely on a plethora of built-in libraries.  This isn't to mention that C tends to run on every platform out there.  I'll also be using GCC instead of MSVC as a compiler, as some light research shows that it generally tends to compile quicker programs.

I have an idea for a game to create with my game engine.  Shocking, I know.  In my initial approach I was planning on making a general-purpose game engine that would be open for everyone to use akin to Godot, but after some looking around that is more than a hefty task that still hasn't reached perfection after a the amount of time that it has been in production.  Am I planning on creating a perfect end product?  No.  But I am planning on making an engine that is specifically good at making the types of games that I would love to make.  In this case, those games tend to be ones that do crazy visual tricks and handle RPG and puzzle systems very well.  This means less of a focus on physics and more of a focus on shaders, rendering, logic, economy, and such the like.  

In another shocking detail, I will not be working on a rendering engine right out of the gate.  I think this one can go without saying too much about why.  It's such a hefty task to start out with that I'm not sure my fragile widdle heart will be able to take it.  Instead, I'll be working on a simple I/O system and some debugging tools while I figure out the rest of the engine's structure.  This will lead into the creation of a nice and easy text-based game with some GUI development on the side, which I will be creating a debugging system with as a dev tool before I do anything else.  Whatever happens after that will be an effort to build up to a 2D game complete with tools for media loading, level editing, and object creation.  Whatever happens after this point is beyond me, but I'm not sure how much further I want to go with my plan anyways as things could go off the rails on day 2.  For now, this is the approach I'm sticking with until I have someone tell me something better.

That's about all I have for my ReadMe pseudo-rant.  I'll update this when I actually have something going on in this repository that is compilable and observable by an outside party.  I'm hoping to apply the knowledge I've gained from being at university and from my career to churn out a good product.  I'm still planning on making some archive of my progress here for future consumption, but I'm not sure if it'll be in blog form or in video form.  In the meantime, keep your eyes peeled for future updoots.  Let's hope this works this time around.

Thanks for your faith, y'all, and enjoy watching me flounder.