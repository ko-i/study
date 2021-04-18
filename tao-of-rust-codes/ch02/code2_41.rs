#[derive(Debug)]
enum IpAddr {
    V4(u8, u8, u8, u8),
    V6(String),
}

fn main() {
    let _x: fn(u8, u8, u8, u8) -> IpAddr = IpAddr::V4;
    let _y: fn(String) -> IpAddr = IpAddr::V6;

    let home_v4 = IpAddr::V4(127, 0, 0, 1);
    let home_v6 = IpAddr::V6(String::from("::ff"));

    println!("{:?}", home_v4);
    println!("{:?}", home_v6);
}