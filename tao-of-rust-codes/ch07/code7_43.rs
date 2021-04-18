pub struct Letter {
    text: String,
}

pub struct EmptyEnvelope {}
pub struct ClosedEnvelope {
    letter: Letter,
}

pub struct PickupLorryHandle {
    done: bool,
}

impl Letter {
    pub fn new(text: String) -> Self {
        Letter {
            text: text,
        }
    }
}

impl EmptyEnvelope {
    pub fn wrap(self, letter: Letter) -> ClosedEnvelope {
        ClosedEnvelope {
            letter: letter,
        }
    }
}

pub fn buy_prestamed_envelope() -> EmptyEnvelope {
    EmptyEnvelope {}
}

impl PickupLorryHandle {
    pub fn pickup(&mut self, envelope: ClosedEnvelope) {
        // give letter
    }

    pub fn done(self) {}
}

impl Drop for PickupLorryHandle {
    fn drop(&mut self) {
        println!("Sent.");
    }
}

pub fn order_pickup() -> PickupLorryHandle {
    PickupLorryHandle {
        done: false,
    }
}

fn main() {
    let letter = Letter::new(String::from("Dear RustFest"));

    let envelope = buy_prestamed_envelope();
    let closed_envelope = envelope.wrap(letter);

    let mut lorry = order_pickup();
    lorry.pickup(closed_envelope);
}