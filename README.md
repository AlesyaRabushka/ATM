# ATM
class Card - данные карточки (номер, срок экспуатации, владелец, пин-код, cvv, баланс)

class Bank - данные счета (номер счета, количество средств и владелец)

class Bankomat - абстрактный класс для банкомата (от него наследуем карточку и банк), содержит основные методы наледуемых классов

class CardSessions - просто кабстрактный класс с двумя методами, которые потом используем в наследниках

class GiveMoney, GetMoney, Payement - абстрактные классы с одним методом(выдача наличных, пополнение краты, перевод средств на счет в банке
