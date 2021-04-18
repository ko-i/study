fn main() {
    let v = [10, 40, 30];

    println!("{:?}", v.contains(&30));
    println!("{:?}", v.contains(&50));

    println!("{:?}", v.starts_with(&[10]));
    println!("{:?}", v.starts_with(&[10, 40]));

    println!("{:?}", v.ends_with(&[40]));
    println!("{:?}", v.ends_with(&[40, 30]));
    println!("{:?}", v.ends_with(&[]));

    let v: &[u8] = &[];
    println!("{:?}", v.starts_with(&[]));
    println!("{:?}", v.ends_with(&[]));
}