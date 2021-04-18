fn main() {
    let a = [1, 2, 3];
    let mut iter = a.iter().rev();

    println!("{:?}", iter.next());
    println!("{:?}", iter.next());
    println!("{:?}", iter.next());
    println!("{:?}", iter.next());
}