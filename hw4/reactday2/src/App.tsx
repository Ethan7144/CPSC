import React, { useState } from 'react';
import logo from './logo.svg';
import Profile from './profile';
import './App.css';


const profiles = [
  'Ethan Jack',
  'Isabel O',
  'Jackie Chan',
  'Matt Loud'
]
function App() {

  const [currentIndex, setCurrentIndex] = useState(0)
  const [activeProfiles, setActiveProfiles] = useState(profiles)
  const onLeftSwipe = () => {
    const newProfiles = [...activeProfiles]
    newProfiles.splice(currentIndex, 1)
    setActiveProfiles(newProfiles)
    if(currentIndex === newProfiles.length){
      setCurrentIndex(currentIndex - 1)
    }
  }

  const onRightSwipe = () => {
    setCurrentIndex(
      (currentIndex + activeProfiles.length + 1) % profiles.length
    )
  }
  return (
    <div className="App">
      <header className="App-header">
        <button onClick = {onLeftSwipe}>&lt;--</button>
        <Profile name = {profiles[currentIndex]}/>
        <button onClick = {onRightSwipe}>--&gt;</button>
      </header>
    </div>
  );
}

export default App;
