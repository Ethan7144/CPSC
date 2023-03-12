
interface ProfileProps{
    name: string
}

function Profile(props: ProfileProps){
    return (
        <h2>{props.name}</h2>
    )
}

export default Profile