from .baseMethod import BaseMethod


# Statuslight
class StatusLight(BaseMethod):
    def method(self, payload=None):
        response = self.socket.send("statuslight")
        return response
