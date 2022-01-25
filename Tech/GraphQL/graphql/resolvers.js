import {people,getById} from './db';

console.log(people);
const resolvers = {
    Query:{
        people:()=>people,
        person:(_,{id})=>getById(id)
    }
}
export default resolvers