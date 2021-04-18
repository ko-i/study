fn main() {
    let mut v = [-5i32, 4, 1, -3, 2];
    v.sort();
    println!("{:?}", v);

    v.sort_by(|a, b| a.cmp(b));
    println!("{:?}", v);

    v.sort_by(|a, b| b.cmp(a));
    println!("{:?}", v);

    v.sort_by_key(|k| k.abs());
    println!("{:?}", v);
}