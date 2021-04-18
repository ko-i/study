fn main() {
    let a = [1, 2, 3];
    let mut iter = a.iter().map(|x| 2 * x);

    println!("{:?}", iter.next());
    println!("{:?}", iter.next());
    println!("{:?}", iter.next());
    println!("{:?}", iter.next());

    println!("{:?}", a);

}