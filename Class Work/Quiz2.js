// Question 3


function clearTextboxes(id){
    const selector = '#${id} > input[type="text"]'
    const inputs = document.querySelectorAll(selector)
    inputs.forEach(input => input.value = '')
}


//Questioon 4

function absorbClicks(selector){
    const match = document.querySelector(selector)
    match.onlick = event =>{
        event.stopPropagation()}
        // match.addEventListener('click',
    }
}


// Midterm review:

#error-overlay > div{
    position: fixed;
    top: 50%;
    left: 50%;
    height: 100%;
    width: 100%;
}


function findInnerText(){
    const selector = 'section > p:nth-shild(2)'
    const innerTexts = []
    const paragraphs = document.querySelectorAll(selector)
    paragraphs.forEach(paragraphs => innerTexts.push(paragraphs.innerText))
    return innerTexts
}

const button = document.querySelector('#boop')
button.onlick() => {
    fetch('/boop', {method: 'POST'})
}


<html>
    <style>
        #output{
        font-size: 48px;
        color: blue;
        text-align: center;
        }
        button {display: inline; }
    </style>
    <body>
        <div>0</div>
        <div>
            <button>Stop</button>
            <button>Reset</button>
        </div>
        <sctipt>
            let count = 0
            const outputElement = document.querySelector('div')
            setInterval(() => {
                count++
                outputElement.innerText = count
            }, 1000)
            
        </sctipt>
    </body>
</html>