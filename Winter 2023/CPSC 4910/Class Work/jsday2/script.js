
// demonstrates that querySelector(All) can be called
// on a specific element to search that subtree
function registerButtonCallbacks() {
    // get all forms in the document/page
    const forms = document.querySelectorAll('form')
    // for each form
    forms.forEach(form => {
        // get all the sections in that form
        const sections = form.querySelectorAll('section')
        // for each section
        sections.forEach(section => {
            // get the (first) button in that section
            const button = section.querySelector('button')
            // button.onclick = () => {}
            button.addEventListener('click', event => {
                event.preventDefault()
                sumSectionScores(section)
            })
        })
    })
}

registerButtonCallbacks()

function sumSectionScores(section) {
    const inputs = section.querySelectorAll(
        'input[type="number"]'
    )
    let total = 0
    inputs.forEach(input => {
        let numValue = input.valueAsNumber
        if(!isNaN(numValue)) {
            total += numValue
        }
    })
    const outputElement = section.querySelector(
        'span'
    )
    outputElement.innerText = total
    //outputElement.innerHTML = '<strong>' + total + '</strong>'
}
/*
function sumSectionScores(formId, sectionName) {
    const inputs = document.querySelectorAll(
        `#${formId} section.${sectionName} input[type="number"]`
    )
    let total = 0
    inputs.forEach(input => {
        let numValue = input.valueAsNumber
        if(!isNaN(numValue)) {
            total += numValue
        }
    })
    const outputElement = document.querySelector(
        `#${formId} section.${sectionName} span`
    )
    outputElement.innerText = total
    //outputElement.innerHTML = '<strong>' + total + '</strong>'
}
*/

function createForm(formId, classTitle, gradeBreakdown) {
    const formElement = document.createElement('form')
    formElement.id = formId
    const classTitleElement = document.createElement('h2')
    classTitleElement.innerText = classTitle
    formElement.appendChild(classTitleElement)
    document.body.appendChild(formElement)

    const sectionNames = Object.keys(gradeBreakdown)
    sectionNames.forEach(sectionName => {
        const sectionElement = document.createElement('section')
        const sectionTitleElement = document.createElement('h3')
        sectionTitleElement.innerText = sectionName
        sectionElement.appendChild(sectionTitleElement)
        const sectionGrades = gradeBreakdown[sectionName]
        for(let i = 0; i < sectionGrades.count; i++) {
            const input = document.createElement('input')
            input.type = 'number'
            sectionElement.appendChild(input)
        }
        formElement.appendChild(sectionElement)
    })
}

const algorithmsGradeBrakedown = {
    Quizzes: {
        percentage: 10,
        count: 4
    },
    Homework: {
        percentage: 25,
        count: 5
    },
    Midterm: {
        percentage: 25,
        count: 1
    },
    Final: {
        percentage: 40,
        count: 1
    }
}

createForm('algorithms-calculator', 'CPSC 4100 - Algorithms', algorithmsGradeBrakedown)
