import random
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim

class DQNNetwork(nn.Module):
    def __init__(self, state_dim, action_dim):
        super(DQNNetwork, self).__init__()
        self.network = nn.Sequential(
            nn.Linear(state_dim, 64),
            nn.ReLU(),
            nn.Linear(64, 64),
            nn.ReLU(),
            nn.Linear(64, action_dim)
        )

    def forward(self, x):
        return self.network(x)

class CognitiveECCMAgent:
    def __init__(self, num_channels=20):
        self.num_channels = num_channels
        self.policy_net = DQNNetwork(num_channels, num_channels)
        self.optimizer = optim.Adam(self.policy_net.parameters(), lr=1e-3)
        self.epsilon = 0.15

    def select_frequency_hop(self, spectrum_state):
        if random.random() < self.epsilon:
            return random.randint(0, self.num_channels - 1)
        
        state_t = torch.FloatTensor(spectrum_state).unsqueeze(0)
        with torch.no_grad():
            q_values = self.policy_net(state_t)
        return torch.argmax(q_values).item()

    def train_step(self, state, action, reward, next_state):
        s_t = torch.FloatTensor(state).unsqueeze(0)
        ns_t = torch.FloatTensor(next_state).unsqueeze(0)
        r_t = torch.tensor([reward], dtype=torch.float32)

        q_current = self.policy_net(s_t)[0][action]
        q_next_max = torch.max(self.policy_net(ns_t))
        q_target = r_t + 0.95 * q_next_max

        loss = nn.MSELoss()(q_current, q_target)
        self.optimizer.zero_grad()
        loss.backward()
        self.optimizer.step()

if __name__ == "__main__":
    agent = CognitiveECCMAgent(num_channels=20)
    mock_spectrum = np.random.uniform(0.0, 1.0, 20)
    selected_channel = agent.select_frequency_hop(mock_spectrum)
    print(f"[ECCM] Cognitive Hopping to Channel: {selected_channel}")