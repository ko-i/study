fn main() {
    let mut s1 = String::from("foo");

    let s2 = "bar";
    let s3 = String::from("bar");

    s1.push_str(s2);
    println!("s1 is {}", s1);
    println!("s2 is {}", s2);

    s1.push_str(&s3);
    println!("s1 is {}", s1);
    println!("s3 is {}", s3);

    let mut s = String::from("lo");
    s.push('l');

    println!("s is {}", s);

    let s1 = String::from("Hello, ");
    let s2 = String::from("world!");
    let s3 = s1 + &s2;
    println!("s3 is {}", s3);

    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");
    let s = s1 + "-" + &s2 + "-" + &s3;
    println!("s is {}", s);

    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");
    let s = format!("{}-{}-{}", s1, s2, s3);
    println!("s is {}", s);
}