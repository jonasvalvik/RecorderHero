<h1 align="center">Recorder Hero - Gamified Learning</h1>

<p align="center">

<img src="https://github.com/jonasvalvik/RecorderHero/assets/6436680/8b99168a-136c-4477-9bca-cf6a99730a5b" alt="TitleImage" width="500">
</p>

## Description

This project involved a physically augmented recorder that saught to provide an enhanced learning experience of the instrument. With bluetooth trasmitted sensory information, the user's fingering and tonation accuracy is tracked and used to play a Guitar Hero like game - Recorder Hero. 

## Tech Stack

- Java (Processing)
- C++ (Arduino)


## Features

* Tracking of fingering accuracy.
* Provides the user with tonation feedback.
* Sends sensory information to a connected computer via bluetooth.
* Features "Twinkle Twinkle Little Star" and "My Heart Will Go On" as playable songs.
* Adjustable playback speed.
* Fully portable system.

<p align="center">
<img src="https://github.com/jonasvalvik/RecorderHero/assets/6436680/488049cc-81d0-4c7c-8c70-1471c2ad6e22" alt="DemoGIF" width="400"> 
   <p align="center">
      Finished program. The user is shown where to put their fingers, and if their pitch is aligned with the corresponding notes. Points are rewarded if the sensory information being transmitted matches the notes of the program. 
   </p>
</p>

## Physical Augmentations
* Thin copper sheets surrounding holes for touch recognition.
* Mounted microphone for tracking pitch.
* Mounted ESP32 for transmitting sonsory information via bluetooth.

<p align="center">
<img src="https://github.com/jonasvalvik/RecorderHero/assets/6436680/f044b552-024c-4763-bc4e-ef9e745014c5" alt="AssembledRecorder" width="415"> 
   <p align="center">
      Assembled recorder. Copper cutouts and microphone are connected to the ESP32, which sends it as bluetooth information.
   </p>
</p>

## Early Iterations

### Pitch Tracking
<p align="center">
<img src="https://github.com/jonasvalvik/RecorderHero/assets/6436680/3d169114-7559-4712-b8ab-c9219f8e7285" alt="EarlyTonation" width="400"> 
   <p align="center">
      Early pitch tracking. Later displayed in Processing.
   </p>
</p>

### Augmented Gloves

A couple iterations were used to augment a pair of gloves to help prepare the user with fingering. Testing proved the idea useless mainly because of sensory overload between each note, but also because of it being bulky to play with.

<p align="center">
<img src="https://github.com/jonasvalvik/RecorderHero/assets/6436680/e7b2fa63-e954-44f9-bbc7-f67d78a02db4" alt="RotorGIF" width="400"> 
<img src="https://github.com/jonasvalvik/RecorderHero/assets/6436680/873da17b-4640-451b-8d63-256e35c79124" alt="RotorGlove" width="345"> 
   <p align="center">
      Augmented gloves with motors attached to each finger providing haptic feedback. Depending on which holes to cover the motors would vibrate accordingly shortly before the corresponding note should be played.
   </p>
</p>
