import random
class AntiJammingAgent:
    def __init__(self, channels=20):
        self.channels = channels
        
    def get_safe_frequency(self):
        return random.randint(0, self.channels - 1)

print("Cognitive ECCM Ready. Hopping frequencies...")
