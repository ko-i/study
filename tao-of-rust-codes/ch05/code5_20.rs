fn foo(mut v: [i32; 3]) -> [i32; 3] {
    v[0] = 3;
    assert_eq!([3, 2, 3], v);
    v
}

fn main() {
    let v = [1, 2, 3];
    foo(v);
    assert_eq!([1, 2, 3], v);
}