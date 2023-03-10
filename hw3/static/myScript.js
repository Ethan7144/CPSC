


async function crewMemberJoin(){
    let result = await fetch('/join', { method: 'POST' })
    return await result.text()
}

async function postWithData(path, data){
    await fetch(path, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    })
}

async function postWithText(path, data){
    await fetch(path, {
        method: 'POST',
        body: data
    })
}

async function getNextTask(crewMemberID){
    let response = await fetch('/crew/' + crewMemberID + '/tasks/next', { method: 'GET'})
    return await response
}

async function cleaning1(crewMemberID){
    const currentPath = '/crew/' + crewMemberID + '/tasks/' + 'cleaning1'
    let response = await fetch(currentPath, { method: 'GET'})
    let givenIndex = await response.json()
    console.log(givenIndex)
    let noDupArray = []
    let sameNum = false
    let size = 0
    for(i = 0; i < givenIndex.length; i++){
        for(j = i + 1; j < givenIndex.length; j++){
            if(givenIndex[i] == givenIndex[j]){
                sameNum = true;
            }
        }
        if(!sameNum){
            noDupArray[size] = givenIndex[i]
            size++
        }
        
        sameNum = false;
    }
    console.log(noDupArray)
    await postWithData(currentPath, noDupArray)
}

async function cleaning2(crewMemberID){
    const currentPath = '/crew/' + crewMemberID + '/tasks/' + 'cleaning2'
    let response = await fetch(currentPath, { method: 'GET'})
    let givenArray = await response.json()

    let numArr = []
    let stringsArr = []

    for(i = 0; i < givenArray.length; i++){
        if(isNaN(givenArray[i])){
            stringsArr.push(givenArray[i])
        } else{
            numArr.push(givenArray[i])
        }
    }
    var object = {"numbers" : numArr, "non-numbers" : stringsArr}

    await postWithData(currentPath, object)
}

async function decoding(crewMemberID){

    const currentPath = '/crew/' + crewMemberID + '/tasks/' + 'decoding'
    const response = await fetch(currentPath, {method:"GET"})
    
    var obj = await response.json()

    const messages = obj.message

    console.log('int = ' + messages )
    var secretmsg = ""

    messages.forEach(position => {
        secretmsg += obj.key[position]
    })
    console.log('msg = ' + secretmsg)
    await postWithText(currentPath, secretmsg)


}

async function repair(crewMemberID){
    const currentPath = '/crew/' + crewMemberID + '/tasks/' + 'repair'
    const response = await fetch(currentPath, {method: 'GET'})

    var currArr = await response.json()


    console.log('currArr = ' + currArr)
    let keysArr = Object.keys(currArr)
    let newArr = []
    for(i = 0; i < keysArr.length; i++){
        var num = currArr[keysArr[i]]
        if(num != 0){   
            if(num < 0){
                num = Math.abs(num)
            }
            num = 1/num
            num = num * num * num
            num = num % 360
        }
        newArr.push(num)
    }
    await postWithData(currentPath, newArr)
}

async function main(){
    const OKAY_CODE = 200
    const STEPS_COMPLETE = 204
    const REPAIR = 500
    const CLEAN_ONE = 'cleaning1'
    const CLEAN_TWO = 'cleaning2'
    const DECODE = 'decoding'

    var isDone = false;

    const crewID = await crewMemberJoin()
    console.log(crewID)
    while(!isDone){

        var nextTaskPromise = await getNextTask(crewID)
        var currentStatus = nextTaskPromise.status
    
        console.log(currentStatus)
    
        if(currentStatus === STEPS_COMPLETE)
        {
            isDone = true
        }

        else if (currentStatus === OKAY_CODE){
            var currentTask = await nextTaskPromise.text()
            console.log("current task: " + currentTask)
            if(currentTask === CLEAN_ONE) {
                await cleaning1(crewID)
            }
            else if(currentTask === CLEAN_TWO) {
                await cleaning2(crewID)
            } 
            else if(currentTask === DECODE) {
                await decoding(crewID)
            }
            
        }

        else if(currentStatus === REPAIR){
            await repair(crewID)
        }
        
    }
    
}