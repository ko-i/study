fn main() {
    let str_ = "boros";
    let mut chars = str_.chars();
    println!("{:?}", chars.next());
    println!("{:?}", chars.next());
    println!("{:?}", chars.next());
    println!("{:?}", chars.next());
    println!("{:?}", chars.next());
    println!("{:?}", chars.next());

    let mut bytes = str_.bytes();
    println!("{:?}", bytes.next());
    println!("{:?}", bytes.next());
    println!("{:?}", bytes.next());
    println!("{:?}", bytes.next());
    println!("{:?}", bytes.next());
    println!("{:?}", bytes.next());
}