const { TestWatcher } = require("jest");

var obj = {
    a:'a',
    b:'b',
    c:'c'
};
function abc(){
    return obj
}
test("1 is 1", () => {
    expect(1).toBe(1);
});

test("abc toEqual", () => {
    expect(abc()).toEqual({
        a:'a',
        b:'b',
        c:'c'
    });
});

test("abc toBe", () => {
    expect(abc()).toBe(obj);
});
