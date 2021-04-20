enum Food {
    Pizza,
    Salad,
}

enum PaymentMode {
    Bitcoin,
    Credit,
}

struct Order {
    count: u8,
    item: Food,
    payment: PaymentMode,
}

fn main() {
    let food_order = Order {
        count: 2,
        item: Food::Salad,
        payment: PaymentMode::Credit,
    };

    let Order {
        count,
        item,
        ..
    } = food_order;

    println!("{}", count);
}