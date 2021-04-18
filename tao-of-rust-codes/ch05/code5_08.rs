fn main() {
    let a = ("a".to_string(), "b".to_string());
    let b = a;
    // println!("{:?}", a);
    println!("{:?}", b);

    let c = (1, 2, 3);
    let d = c;
    println!("{:?}", c);
    println!("{:?}", d);
}