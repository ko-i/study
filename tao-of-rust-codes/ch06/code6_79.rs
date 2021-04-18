fn main() {
    let numbers = vec![1, 2, 3, 4, 5, 6];
    let mut iter = numbers.into_iter();

    println!("{:?}", iter.next());
    println!("{:?}", iter.next_back());
    println!("{:?}", iter.next());
    println!("{:?}", iter.next_back());
    println!("{:?}", iter.next());
    println!("{:?}", iter.next_back());
    println!("{:?}", iter.next());
    println!("{:?}", iter.next_back());
}