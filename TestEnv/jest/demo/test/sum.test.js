import add from '../src/sum';

test('sum function test',()=>{
    const result = add(1,2,3,4)
    expect(result).toEqual(10);
});