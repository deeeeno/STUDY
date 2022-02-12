const users = [
   
];
export default {
    find(id){
        const ret = users.find((user)=>user.id === id);
        return ret === undefined ? {} : ret
    },
    findAll(){
        return users;
    },
    create(...list){
        users.push(...list);
    },
    destroy(id){
        const idx = users.findIndex((user)=>user.id===id);
        users.splice(id,1);
    },
    destroyAll(){
        users.splice(0);
    },
    update(id,user){
        const idx = users.findIndex((user)=>user.id===id);
        users[idx] = user;
    }
}
