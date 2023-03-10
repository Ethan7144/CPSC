import React, { useState } from 'react';
import greetings from './greetings';
import GreeterEmoji from './GreeterEmoji';
const languages: string[] = ['English', 'Spanish', 'French']

// more or less std::map<string,string> or dictionary<string,string>
const buttonText: {[key: string]: string}= {
    'English': 'Continue',
    'Spanish': 'Sigue',
    'French': 'Continuer'
  }



function Greeter(){
    //let currentIndex = 0
    // example of a "hook" its asking react for a special object
    // that it will associate with Greeter
    /*const currentIndexState = useState(0)
    const currentIndex = currentIndexState[0]
    const currentIndexSetter = currentIndexState[1]
    */
   // shorthand, called "destructuring"
   const [currentIndex, currentIndexSetter] = useState(0)
    const buttonClicked = () => {
            console.log('continue clicked')
            currentIndexSetter((currentIndex + 1) % languages.length)
    }
return (
    
    <div>
    <h1>{greetings[languages[currentIndex]]}
        <GreeterEmoji />
    </h1>
    <button onClick ={buttonClicked}>{buttonText[languages[currentIndex]]}</button>
    </div>
)
}

export default Greeter