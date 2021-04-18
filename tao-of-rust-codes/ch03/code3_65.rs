fn main() {
    let a = std::u32::MAX;
    let b = a as u16;
    println!("b = {}", b);

    let e = -1i32;
    let f = e as u32;
    println!("{:?}", e.abs());
    println!("{:?}", f);
}