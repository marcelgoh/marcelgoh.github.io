---
layout: post
title: HackPrinceton and CourseTalk
date: 2018-11-14
published: true
excerpt_separator:  <!--more-->
---
This past weekend, I had the amazing opportunity to attend [HackPrinceton](https://hackprinceton.com) at Princeton University! It was nice to drive seven hours away from Montreal and get away from school for a while, but the actual competition was far from relaxing! It was the first hackathon for me and my two teammates, so we decided to try something simple and presentable. I thought it'd be fun in this post to go through what it was like working on [CourseTalk](https://github.com/marcelgoh/hackprinceton-2018), a web-based chat app and my first real team project.  

<!--more-->
### Background
The motivation for CourseTalk (link to the hosted demo [here](https://course-talk.herokuapp.com)) is the general lack of engagement and enthusiasm in school discussion boards. Many universities' course-management systems have some kind of forum for students to post questions or talk amongst themselves, but the permanency and formality of having to submit posts means that most students resort to Facebook groups and chats for collaboration. Some students are unaware of the existence of these groups and working through social media makes the average student extremely liable to distraction. The success of platforms like Slack made us think that perhaps if something more informal and immediate were integrated into students' default course pages, students would have an easier time chatting with other students about schoolwork.  

### The demo
We implemented the demo as a single-page web application that asks the user for a username and gives them a list of chat rooms they can join. In real life, we imagine this would be implemented via the same database that shows the correct courses on a student's course page. It simply links the user to the chat rooms of the courses they're currently enrolled in. Within the chat app, users chat in real-time, and the chat has features like online status buttons, autoscrolling, and typing status notifications. The application only supports text in our demo, but the [Chatkit](https://pusher.com/chatkit) API we used can be extended to host multimedia as well.  

![chat](/media/coursetalk/chat.jpg){: .center-image}

### How it was made
CourseTalk was made using [React.js](https://reactjs.org). Because we were new to JavaScript and React, we spent the first half of the hackathon watching and following online tutorials and then tweaking as needed. By 4 a.m. on the second morning, we basically had the chat page above working. However, that's when everything started to fall apart. The tutorial we'd followed used two instances of [Node.js](https://nodejs.org) as its backend: one to run the web application on [Express.js](https://expressjs.com) and one to support the React front-end. (At least that's what we sort of deduced. I'm still don't fully understand how everything works.) This meant that our app would work on our localhost server, which happily supplies two ports, but wouldn't work when uploaded to GitHub Pages, which (we think) only gives you one port to work with.  

We spent much of the second day tinkering with different parts of the app, trying to see if we could make everything work without the second port, but we couldn't figure it out. In the end, a friend from a different team came and helped us port our project to [Webpack](https://webpack.js.org). He also suggested we use [Heroku](https://heroku.com), which ended up being much easier to host our app on, because it works out-of-the-box with apps hosted on GitHub. Finally, our app was on the actual internet!  

The last part of the project was the most difficult but also the most rewarding. We wanted to have a landing page in between the login page and the chat app that allows you to switch between different chat rooms. At this point we couldn't rely on video tutorials anymore, we were sleep-deprived and stressed and time was running out. I learned the most about React during this part, because we had so many different components that all had to pass information to one another. I learned that mutating state is a frustrating and largely wrong approach in React programming, because the `setState()` function is asynchronous! (I wasted an inordinate amount of time because I didn't know this.) At around 5 a.m. the second night, four hours before the submission deadline, we had the app functionality working. During this time, my teammates worked on making the login page more presentable using CSS.

![login](/media/coursetalk/login.jpg){: .center-image}

We pushed the final project to Heroku and it didn't work. In the end we found out that the app would work without the new CSS, and by that time we were already falling asleep at our desks, so we just created a `stable` branch with the old CSS stylesheet and posted that to Heroku. It didn't look as nice as we wanted, but at least it worked. The `master` branch still contains the nice CSS and works locally but not on Heroku for some reason.

### Conclusion
~~Web development sucks and should be avoided at all costs.~~ This was my first proper exposure to web development, and though I had known that we would have to use some APIs, I completely underestimated how frustrating that would be under a time limit. It didn't feel like we had enough time to learn anything properly, so we just slapped together a bunch of different frameworks and tools. We did manage to create a working result, but in the future I think a bit more preparation would probably be a good idea. In a future hackathon, I would be hesitant to make another web application because of how many dependencies and components there were to keep track of, and also because I'd want to try something new, like maybe making a small game. But overall, I'm happy with what I learned over the weekend and I'm still really proud of the simple, slightly janky chat app we created in 36 hours!