fn main() {
    let a: [i32; 3] = [1, 2, 3];
    let mut iter = a.iter();

/*
    let a = vec![1, 2, 3];
    let mut iter = a.iter();
    println!("{:?}", a);
    println!("{:?}", iter);
*/

    println!("{:?}", iter.size_hint());
    iter.next();
    println!("{:?}", iter.size_hint());
    iter.next();
    println!("{:?}", iter.size_hint());
    iter.next();
    println!("{:?}", iter.size_hint());
    iter.next();
    println!("{:?}", iter.size_hint());
}