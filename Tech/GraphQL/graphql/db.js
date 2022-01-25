export const people = [
    {
        id: 1,
        name:'dino',
        age:18,
        gender:'male'
    },
    {
        id: 2,
        name:'bino',
        age:19,
        gender:'female'
    },
    {
        id: 3,
        name:'cino',
        age:20,
        gender:'male'
    },
    {
        id: 4,
        name:'qino',
        age:21,
        gender:'female'
    },
    {
        id: 5,
        name:'zio',
        age:22,
        gender:'male'
    }
]
export const getById = id=>{
    const filtered = people.filter(ele=> id === ele.id)
    return filtered[0];
}