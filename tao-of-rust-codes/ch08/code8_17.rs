fn main() {
    let mut s = String::from("hållo");

    s.remove(3);
    println!("{:?}", s);
    println!("{:?}", s.pop());
    println!("{:?}", s.pop());
    println!("{:?}", s.pop());
    println!("{:?}", s);

    let mut s = String::from("hållo");
    s.truncate(3);
    println!("{:?}", s);

    s.clear();
    println!("{:?}", s);

    let mut s = String::from("å is alpha, ß is beta");
    let beta_offset = s.find('ß').unwrap_or(s.len());
    let t: String = s.drain(..beta_offset).collect();
    println!("{:?}", t);
    println!("{:?}", s);

    s.drain(..);
    println!("{:?}", s);
}