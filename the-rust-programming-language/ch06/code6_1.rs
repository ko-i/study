enum IpAddrKind {
    V4,
    V6,
}

struct IpAddr {
    kind: IpAddrKind,
    address: String,
}

enum IpAddr2 {
    V4(String),
    V6(String),
}

enum IpAddr3 {
    V4(u8, u8, u8, u8),
    V6(String),
}

fn route(_ip_type: IpAddrKind) {

}

fn main() {
    let _four = IpAddrKind::V4;
    let _six = IpAddrKind::V6;

    route(IpAddrKind::V4);
    route(IpAddrKind::V6);

    let _home = IpAddr {
        kind: IpAddrKind::V4,
        address: String::from("127.0.0.1"),
    };

    let _loopback = IpAddr {
        kind: IpAddrKind::V6,
        address: String::from("::1"),
    };

    let _home2 = IpAddr2::V4(String::from("127.0.0.1"));
    let _loopback2 = IpAddr2::V6(String::from("::1"));

    let _home3 = IpAddr3::V4(127, 0, 0, 1);
    let _loopback3 = IpAddr3::V6(String::from("::1"));
}

