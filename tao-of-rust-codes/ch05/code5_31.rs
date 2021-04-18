fn the_longest(s1: &str, s2: &str) -> &str {
    if s1.len() > s2.len() 
    {
        s1
    } else {
        s2
    }
}

fn main() {
    let s1 = String::from("Rust");
    let s1_r = &s1;

    {
        let s2 = String::from("C");
        let res = the_longest(s1_r, &s2);

        println!("{:?} is the longest.", res);
    }
}