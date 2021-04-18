use std::iter::Peekable;

fn parse_number<I>(tokens: &mut Peekable<I>) -> u32 where I: Iterator<Item = char> {
    let mut n = 0;

    loop {
        match tokens.peek() {
            Some(r) if r.is_digit(10) => {
                n = n * 10 + r.to_digit(10).unwrap();
            },

            _ => return n,
        }

        tokens.next();
    }
}

fn main() {
    let mut chars = "226153980,1766319049".chars().peekable();

    println!("{:?}", parse_number(&mut chars));
    chars.next();
    println!("{:?}", parse_number(&mut chars));
    println!("{:?}", chars.next());
}