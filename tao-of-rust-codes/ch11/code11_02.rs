trans1(amount, account_from, account_to) {
    if(account_from.balance < amount) return False;

    account_to.balance += amount;
    account_from.balance -= amount;

    return True;
}

trans2(amount, account_from, account_to) {
    atomic {
        bal = account_from.balance;
    }

    if(bal < amount) {
        return False;
    }

    atomic {
        account_to += amount;
    }

    atomic {
        account_from -= amount;
    }

    return True;
}

trans3(amount, account_from, account_to) {
    atomic {
        if(account_from.balance < amount)
        {
            return False;
        }

        account_to.balance += amount;
        account_from.balance -= amount;

        return True;
    }
}

trans4(amount, account_from, account_to) {
    account_from.activity = True;
    account_to.activity = True;

    atomic {
        if(account_from.balance < amount) {
            returnn False;
        }

        account_to.balance += amount;
        account_from.balance -= amount;

        return True;
    }
}