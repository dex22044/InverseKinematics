#include "ArmIK.h"

void ArmIK::AddJoint(float len) {
	Joint newJoint = { 0 };
	newJoint.len = len;
	joints.push_back(newJoint);
}

void ArmIK::ForwardKinematics(int startJoint) {
	joints[startJoint].globalAngle = (startJoint > 0 ? joints[startJoint - 1].globalAngle : 0) + joints[startJoint].localAngle;

	for (int i = startJoint + 1; i < joints.size(); i++) {
		joints[i].globalAngle = joints[i - 1].globalAngle + joints[i].localAngle;
		joints[i].xpos = joints[i - 1].xpos + sin(joints[i - 1].globalAngle) * joints[i - 1].len;
		joints[i].ypos = joints[i - 1].ypos + cos(joints[i - 1].globalAngle) * joints[i - 1].len;
	}

	xEnd = joints[joints.size() - 1].xpos + sin(joints[joints.size() - 1].globalAngle) * joints[joints.size() - 1].len;
	yEnd = joints[joints.size() - 1].ypos + cos(joints[joints.size() - 1].globalAngle) * joints[joints.size() - 1].len;
}

void ArmIK::InverseKinematics(float xTarget, float yTarget, int steps) {
	for (int i = 0; i < steps; i++) {
		joints[joints.size() - 1].localAngle = atan2(xTarget - joints[joints.size() - 1].xpos, yTarget - joints[joints.size() - 1].ypos) - joints[joints.size() - 2].globalAngle;
		this->ForwardKinematics(joints.size() - 2);
		for (int i = joints.size() - 2; i > 0; i--) {
			this->ForwardKinematics(i - 1);
			float currentAngle = atan2(xEnd - joints[i].xpos, yEnd - joints[i].ypos);
			float targetAngle = atan2(xTarget - joints[i].xpos, yTarget - joints[i].ypos);
			joints[i].globalAngle -= currentAngle - targetAngle;
			joints[i].localAngle = joints[i].globalAngle - joints[i - 1].globalAngle;
		}
		this->ForwardKinematics(0);
		float currentAngle = atan2(xEnd, yEnd);
		float targetAngle = atan2(xTarget, yTarget);
		joints[0].localAngle -= currentAngle - targetAngle;
	}
	this->ForwardKinematics(0);
	joints[joints.size() - 1].localAngle = atan2(xTarget - joints[joints.size() - 1].xpos, yTarget - joints[joints.size() - 1].ypos) - joints[joints.size() - 2].globalAngle;
}